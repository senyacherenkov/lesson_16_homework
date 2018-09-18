#include <iostream>
#include <string>
#include "observer.h"

void Registrator::update(std::vector<std::string>& newCommands, long time)
{
    std::string output;

    //writing to stdout
    output.append("bulk: ");

    for(const auto& command: newCommands) {
        output.append(" ");
        output.append(command);
        output.append(",");
    }
    std::cout << output << std::endl;

    //writing to file
    std::string nameOfFile("bulk");
    nameOfFile.append(std::to_string(time));
    nameOfFile.append(".log");

    m_bulkLog.open(nameOfFile.c_str());
    m_bulkLog << output;
    m_bulkLog.close();
}
