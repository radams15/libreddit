//
// Created by rhys on 01/05/22.
//

#ifndef REDDIT_API_H
#define REDDIT_API_H

#if defined(_WIN32) && !NO_EXPORT
#    ifdef LIBRARY_EXPORTS
#        define LIBRARY_API __declspec(dllexport)
#    else
#        define LIBRARY_API __declspec(dllimport)
#    endif
#else
#    define LIBRARY_API
#endif

#endif //REDDIT_API_H
