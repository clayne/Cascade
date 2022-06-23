/*
 *  Cascade Image Editor
 *
 *  Copyright (C) 2022 Till Dechent and contributors
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "log.h"

#include <iostream>

#include <QFile>
#include <QLoggingCategory>

namespace Cascade
{

Q_LOGGING_CATEGORY(lcVk, "qt.vulkan")

std::shared_ptr<Log> Log::sLogger;
QFile Log::sOutFile;
QTextStream Log::sStream;

void Log::messageHandler(QtMsgType type, const QMessageLogContext& context, const QString& msg)
{
    QString txt = QString("[VULKAN] %1").arg(msg);
    writeToFile(txt);
    console(txt);

    Q_UNUSED(type);
    Q_UNUSED(context);
}

void Log::Init()
{
    QLoggingCategory::setFilterRules(QStringLiteral("qt.vulkan=true"));

    QFile::remove("Cascade.log");

    sOutFile.setFileName("Cascade.log");
    sOutFile.open(QIODevice::WriteOnly | QIODevice::Append);
    sStream.setDevice(&sOutFile);

    qInstallMessageHandler(messageHandler);
}

void Log::debug(const QString& s)
{
    QString txt = QString("[DEBUG] %1").arg(s);
    writeToFile(txt);
    console(txt);
}

void Log::info(const QString& s)
{
    QString txt = QString("[INFO] %1").arg(s);
    writeToFile(txt);
    console(txt);
}

void Log::warning(const QString& s)
{
    QString txt = QString("[WARNING] %1").arg(s);
    writeToFile(txt);
    console(txt);
}

void Log::critical(const QString& s)
{
    QString txt = QString("[CRITICAL] %1").arg(s);
    writeToFile(txt);
    console(txt);
}

void Log::fatal(const QString& s)
{
    QString txt = QString("[FATAL] %1").arg(s);
    writeToFile(txt);
    console(txt);
}

void Log::console(const QString& s)
{
    std::cout << s.toStdString() << std::endl;
}

void Log::writeToFile(const QString& s)
{
    sStream << s << "\n";
    sStream.flush();
}
} // namespace Cascade
