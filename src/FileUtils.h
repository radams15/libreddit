//
// Created by Rhys on 06/07/2022.
//

#ifndef REDDIT_FILEUTILS_H
#define REDDIT_FILEUTILS_H

#include <string>

namespace FileUtils {
    std::string get_extension(std::string path);

    std::string get_username();

    bool exists(std::string path);
}

#endif //REDDIT_FILEUTILS_H
