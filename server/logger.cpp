
#include "logger.hpp"

static Logger * logInstance = 0;

Logger::Logger(Urho3D::Context * context )
    :Urho3D::Object(context)
{
    logInstance = this;
}

Logger::~Logger()
{
    logInstance = 0;
}

src::severity_logger<SeverityLevel> & Logger::ExportLogStream()
{

    assert(logInstance);
    return logInstance->GetSeverityLog();
}
