#include "ara/log/logging.h"
#include <unordered_map>
#include <mutex>

namespace ara {
namespace log {

std::once_flag initOnce;
std::unordered_map<std::string, std::unique_ptr<Logger>> ctxMap;
std::mutex registryMtx;

void InitLogging(std::string  /*appId*/,
                 std::string  /*appDesc*/,
                 LogLevel     /*defLevel*/,
                 LogMode      /*mode*/,
                 std::string  /*dirPath*/) noexcept
{
  std::call_once(initOnce, []{
      // Stub: real backend setup goes here
  });
}

Logger& CreateLogger(std::string ctxId, std::string ctxDesc) noexcept {
  std::lock_guard lock(registryMtx);
  auto& ptr = ctxMap[ctxId];
  if (!ptr) ptr.reset(new Logger{std::move(ctxId), std::move(ctxDesc)});
  return *ptr;
}

}// namespace log
} // namespace log
