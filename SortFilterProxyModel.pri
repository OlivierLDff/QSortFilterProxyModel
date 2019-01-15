!contains( CONFIG, c\+\+1[14] ): warning("SortFilterProxyModel needs at least c++11, add CONFIG += c++11 to your .pro")

INCLUDEPATH += $$PWD/src

HEADERS += $$PWD/src/qqmlsortfilterproxymodel.h \
    $$PWD/src/filters/filter.h \
    $$PWD/src/filters/filtercontainer.h \
    $$PWD/src/filters/rolefilter.h \
    $$PWD/src/filters/valuefilter.h \
    $$PWD/src/filters/indexfilter.h \
    $$PWD/src/filters/regexpfilter.h \
    $$PWD/src/filters/rangefilter.h \
    $$PWD/src/filters/expressionfilter.h \
    $$PWD/src/filters/filtercontainerfilter.h \
    $$PWD/src/filters/anyoffilter.h \
    $$PWD/src/filters/alloffilter.h \
    $$PWD/src/sorters/sorter.h \
    $$PWD/src/sorters/sortercontainer.h \
    $$PWD/src/sorters/rolesorter.h \
    $$PWD/src/sorters/stringsorter.h \
    $$PWD/src/sorters/expressionsorter.h \
    $$PWD/src/proxyroles/proxyrole.h \
    $$PWD/src/proxyroles/proxyrolecontainer.h \
    $$PWD/src/proxyroles/joinrole.h \
    $$PWD/src/proxyroles/switchrole.h \
    $$PWD/src/proxyroles/expressionrole.h \
    $$PWD/src/proxyroles/singlerole.h \
    $$PWD/src/proxyroles/regexprole.h \
    $$PWD/src/sorters/filtersorter.h \
    $$PWD/src/proxyroles/filterrole.h

SOURCES += $$PWD/src/qqmlsortfilterproxymodel.cpp \
    $$PWD/src/filters/filter.cpp \
    $$PWD/src/filters/filtercontainer.cpp \
    $$PWD/src/filters/rolefilter.cpp \
    $$PWD/src/filters/valuefilter.cpp \
    $$PWD/src/filters/indexfilter.cpp \
    $$PWD/src/filters/regexpfilter.cpp \
    $$PWD/src/filters/rangefilter.cpp \
    $$PWD/src/filters/expressionfilter.cpp \
    $$PWD/src/filters/filtercontainerfilter.cpp \
    $$PWD/src/filters/anyoffilter.cpp \
    $$PWD/src/filters/alloffilter.cpp \
    $$PWD/src/filters/filtersqmltypes.cpp \
    $$PWD/src/sorters/sorter.cpp \
    $$PWD/src/sorters/sortercontainer.cpp \
    $$PWD/src/sorters/rolesorter.cpp \
    $$PWD/src/sorters/stringsorter.cpp \
    $$PWD/src/sorters/expressionsorter.cpp \
    $$PWD/src/sorters/sortersqmltypes.cpp \
    $$PWD/src/proxyroles/proxyrole.cpp \
    $$PWD/src/proxyroles/proxyrolecontainer.cpp \
    $$PWD/src/proxyroles/joinrole.cpp \
    $$PWD/src/proxyroles/switchrole.cpp \
    $$PWD/src/proxyroles/expressionrole.cpp \
    $$PWD/src/proxyroles/proxyrolesqmltypes.cpp \
    $$PWD/src/proxyroles/singlerole.cpp \
    $$PWD/src/proxyroles/regexprole.cpp \
    $$PWD/src/sorters/filtersorter.cpp \
    $$PWD/src/proxyroles/filterrole.cpp
