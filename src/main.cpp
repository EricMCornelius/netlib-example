#include <boost/network/protocol/http/client.hpp>
#include <iostream>

namespace http = boost::network::http;

int main(int argc, char *argv[]) {
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " url query" << std::endl;
    return 1;
  }

  try {
    http::client client;
    http::client::request request(argv[1]);

    std::string query(argv[2]);
    request.add_header(std::make_pair("Content-Length", std::to_string(query.size())));
    request.body(query);
    http::client::response response = client.post(request);

    std::cout << body(response) << std::endl;
  }
  catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  return 0;
}
