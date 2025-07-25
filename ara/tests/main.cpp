#include <ara/log/logging.h>

int main() {
  ara::log::InitLogging("APP", "Demo Application",
                        ara::log::LogLevel::kDebug,
                        ara::log::LogMode::kConsole);

  auto& mainLog = ara::log::CreateLogger("MAIN", "Main Context");

  mainLog.LogInfo()    << "Hello AUTOSAR!";
  mainLog.LogDebug()   << "Pi ≈ " << 3.14159;
  mainLog.LogError()   << "Error Code: " << 127;

  return 0;
}
