//
// Created by Rhys on 06/07/2022.
//

#include "FileUtils.h"

#if defined(__UNIX__) || defined(__APPLE__)
#include <unistd.h>
#include <pwd.h>
#include <sys/stat.h>
#elif defined(WIN32)
#include <windows.h>
#include <lmcons.h>
#endif

#include <iostream>
#include <fstream>
#include <sstream>

std::string FileUtils::get_username() {
#if defined(__unix__) || defined(__APPLE__)
    uid_t uid = getuid(); // https://stackoverflow.com/questions/8953424/how-to-get-the-username-in-c-c-in-linux
    struct passwd* pw = getpwuid(uid);
    if (pw){
        return std::string(pw->pw_name);
    }

    std::cerr << "Cannot find unix username!" << std::endl;
    _exit(1);
#elif WINDOWS
    char username[UNLEN+1]; // https://stackoverflow.com/questions/11587426/get-current-username-in-c-on-windows
    DWORD username_len = UNLEN+1;
    GetUserName(username, &username_len);
    return std::string(username);
#else
#error Cannot determine OS (get_username)!
#endif
}

std::string FileUtils::get_extension(std::string path) {
    return path.substr(path.find_last_of('.') + 1);
}

bool FileUtils::exists(std::string path) {
#if defined(__unix__) || defined(__APPLE__)
    // Adapted from https://stackoverflow.com/questions/3828192/checking-if-a-directory-exists-in-unix-system-call
    struct stat sb;
    if (stat(path.c_str(), &sb) == 0){
        return true;
    }
    return false;
#elif defined(WIN32)
    // Adapted from https://stackoverflow.com/questions/8233842/how-to-check-if-directory-exist-using-c-and-winapi
    DWORD ftyp = GetFileAttributesA(path.c_str());
    if (ftyp == INVALID_FILE_ATTRIBUTES){
        return false;
    }

    if (ftyp){
        return true;
    }

    return false;
#else
#error Cannot determine OS (exists)!
#endif
}


std::string FileUtils::get_save_path() {
#if defined(__APPLE__)
    return "/Users/"+get_username() + "/Library/JReddit/";
#elif defined(__UNIX__)
    return "/home/"+get_username() + "/.config/JReddit/";
#elif defined(WIN32)
    return "/JReddit/";
#else
    #error Cannot determine OS (get_save_path)!
#endif
}

std::string FileUtils::get_cache_path() {
#if defined(__APPLE__)
    return "/Users/"+FileUtils::get_username() + "/Library/JReddit/cache/";
#elif defined(__UNIX__)
    return "/home/"+FileUtils::get_username() + "/.cache/JReddit/";
#elif defined(WIN32)
    return "/JReddit/cache/";
#else
    #error Cannot determine OS (get_save_path)!
#endif
}

std::string FileUtils::read(std::string path) {
    std::ifstream in(path, 'r');

    std::stringstream out;

    out << in.rdbuf();

    in.close();

    return out.str();
}
