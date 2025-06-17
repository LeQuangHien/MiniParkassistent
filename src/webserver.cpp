#include "webserver.hpp"
#include <microhttpd.h>
#include <string>
#include <sstream>
#include <fstream>
#include <thread>
#include <chrono>

extern float current_distance;

#define PORT 8080

static MHD_Result answer_to_connection(void *cls, struct MHD_Connection *connection,
                                       const char *url, const char *method,
                                       const char *version, const char *upload_data,
                                       size_t *upload_data_size, void **con_cls) {
    std::string response;
    if (std::string(url) == "/distance") {
        std::ostringstream ss;
        ss << "{ \"distance_cm\": " << current_distance << " }";
        response = ss.str();
    } else {
        std::ifstream file("web/index.html");
        if (!file) return MHD_NO;
        std::stringstream buffer;
        buffer << file.rdbuf();
        response = buffer.str();
    }

    struct MHD_Response *mhd_response;
    mhd_response = MHD_create_response_from_buffer(response.length(),
                    (void *)response.c_str(), MHD_RESPMEM_MUST_COPY);
    int ret = MHD_queue_response(connection, MHD_HTTP_OK, mhd_response);
    MHD_destroy_response(mhd_response);
    return ret;
}

void start_webserver(float &distance) {
    struct MHD_Daemon *daemon;
    daemon = MHD_start_daemon(MHD_USE_SELECT_INTERNALLY, PORT, NULL, NULL,
                              &answer_to_connection, NULL, MHD_OPTION_END);
    if (daemon == NULL) {
        printf("Failed to start web server\n");
        return;
    }

    printf("Webserver läuft auf http://<IP-Adresse>:%d\n", PORT);
    while (true) std::this_thread::sleep_for(std::chrono::seconds(1));
}
