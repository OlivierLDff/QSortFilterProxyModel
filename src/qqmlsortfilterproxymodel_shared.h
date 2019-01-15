#ifndef QQMLSORTFILTERPROXYMODELSHARED_H
#define QQMLSORTFILTERPROXYMODELSHARED_H

// ─────────────────────────────────────────────────────────────
//                  DECLARATION
// ─────────────────────────────────────────────────────────────

#ifdef WIN32
    #ifdef SFPM_SHARED // Shared build
        #define SFPM_API_ __declspec(dllexport)
    #elif SFPM_STATIC  // No decoration when building staticlly
        #define SFPM_API_
    #else               // Link to lib 
        #define SFPM_API_ __declspec(dllimport)
    #endif
#else
    #define SFPM_API_
#endif

#ifdef SFPM_USE_NAMESPACE
#ifndef SFPM_NAMESPACE
#define SFPM_NAMESPACE Sfpm
#endif
#define SFPM_NAMESPACE_START namespace SFPM_NAMESPACE {
#define SFPM_NAMESPACE_END }
#define SFPM_USING_NAMESPACE using namespace SFPM_NAMESPACE;
#else
#undef SFPM_NAMESPACE
#define SFPM_NAMESPACE
#define SFPM_NAMESPACE_START
#define SFPM_NAMESPACE_END
#define SFPM_USING_NAMESPACE
#endif

#ifndef SFPM_NAMESPACE_IID
#define SFPM_NAMESPACE_IID "fr.grecko.SortFilterProxyModel"
#endif

#endif
