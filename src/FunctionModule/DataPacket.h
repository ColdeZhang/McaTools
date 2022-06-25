//
// Created by Deer on 2022/6/22.
//

#ifndef MCATOOLS_DATAPACKET_H
#define MCATOOLS_DATAPACKET_H

#include "../include.h"

namespace McaTools {

    class DataPacket {
    public:
        DataPacket();

        std::string GetServerPath(){
            return server_path;
        }

        void SetServerPath(std::string &path){
            server_path = path;
        }

    private:
        std::string server_path;

    };

} // McaTools

#endif //MCATOOLS_DATAPACKET_H
