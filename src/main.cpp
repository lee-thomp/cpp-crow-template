#include <string>

#include "crow.h"

std::string hello_world ()
{
  return "Hello world!";
}

int main()
{
  crow::SimpleApp app;

  CROW_ROUTE(app, "/")(hello_world);

  app.port(8888).multithreaded().run();
  
  return 0;
}
