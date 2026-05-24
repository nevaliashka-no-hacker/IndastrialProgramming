#include <iostream>
#include <atomic>
#include <string>
#include <cstdlib>
#include "httplib.h"

std::atomic<int> request_counter{0};

int main() {
    const char* port_str = std::getenv("APP_PORT");
    int port = port_str ? std::stoi(port_str) : 8080;

    httplib::Server svr;

    svr.Get("/", [](const httplib::Request&, httplib::Response& res) {
        int count = ++request_counter;
        res.set_content("Hello from container #" + std::to_string(count), "text/plain");
    });

    svr.Get("/health", [](const httplib::Request&, httplib::Response& res) {
        res.set_content("OK", "text/plain");
    });

    svr.Get("/metrics", [](const httplib::Request&, httplib::Response& res) {
        std::string metrics = "http_requests_total " + std::to_string(request_counter.load()) + "\n";
        res.set_content(metrics, "text/plain; version=0.0.4");
    });

    std::cout << "Server started on port " << port << std::endl;
    svr.listen("0.0.0.0", port);
    return 0;
}