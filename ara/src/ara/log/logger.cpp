#include "ara/log/logger.h"

namespace ara{
namespace log {

Logger::Logger(std::string id, std::string desc) noexcept
  : contextId_{std::move(id)}, contextDesc_{std::move(desc)} {}

bool Logger::IsEnabled(LogLevel lvl) const noexcept {
  std::scoped_lock lock(mtx_);
  return static_cast<std::uint8_t>(lvl) <= static_cast<std::uint8_t>(threshold_);
}

} // namespace log
} // namespace ara
