// ─────────────────────────────────────────────────────────────
//                  INCLUDE
// ─────────────────────────────────────────────────────────────

// C Header

// C++ Header

// Qt Header

// Dependencies Header

// Application Header
#include <SortFilterProxyModel/utils.h>

#include <SortFilterProxyModel/filters/alloffilter.h>
#include <SortFilterProxyModel/filters/anyoffilter.h>
#include <SortFilterProxyModel/filters/expressionfilter.h>
#include <SortFilterProxyModel/filters/filter.h>
#include <SortFilterProxyModel/filters/filtercontainer.h>
#include <SortFilterProxyModel/filters/filtercontainerfilter.h>
#include <SortFilterProxyModel/filters/indexfilter.h>
#include <SortFilterProxyModel/filters/rangefilter.h>
#include <SortFilterProxyModel/filters/regexpfilter.h>
#include <SortFilterProxyModel/filters/rolefilter.h>
#include <SortFilterProxyModel/filters/valuefilter.h>

#include <SortFilterProxyModel/proxyroles/expressionrole.h>
#include <SortFilterProxyModel/proxyroles/filterrole.h>
#include <SortFilterProxyModel/proxyroles/joinrole.h>
#include <SortFilterProxyModel/proxyroles/proxyrole.h>
#include <SortFilterProxyModel/proxyroles/proxyrolecontainer.h>
#include <SortFilterProxyModel/proxyroles/regexprole.h>
#include <SortFilterProxyModel/proxyroles/switchrole.h>

#include <SortFilterProxyModel/sorters/expressionsorter.h>
#include <SortFilterProxyModel/sorters/filtersorter.h>
#include <SortFilterProxyModel/sorters/rolesorter.h>
#include <SortFilterProxyModel/sorters/sorter.h>
#include <SortFilterProxyModel/sorters/stringsorter.h>
#include <SortFilterProxyModel/sorters/sortercontainer.h>

#include <SortFilterProxyModel/qqmlsortfilterproxymodel.h>

// ─────────────────────────────────────────────────────────────
//                  DECLARATION
// ─────────────────────────────────────────────────────────────

// ─────────────────────────────────────────────────────────────
//                  FUNCTIONS
// ─────────────────────────────────────────────────────────────

static const char* _defaultUri = "SortFilterProxyModel";
static const char** _uri = &_defaultUri;
static quint8 _major = 1;
static quint8 _minor = 0;

static void Sfpm_registerTypes()
{
    qmlRegisterType<qqsfpm::QQmlSortFilterProxyModel>(*_uri, _major, _minor, "SortFilterProxyModel");

    qmlRegisterType<qqsfpm::AllOfFilter>(*_uri, _major, _minor, "AllOf");
    qmlRegisterType<qqsfpm::AnyOfFilter>(*_uri, _major, _minor, "AnyOf");
    qmlRegisterType<qqsfpm::ExpressionFilter>(*_uri, _major, _minor, "ExpressionFilter");
    qmlRegisterUncreatableType<qqsfpm::Filter>(*_uri, _major, _minor, "Filter", "Filter is an abstract class");
    qmlRegisterInterface<qqsfpm::FilterContainer>("FilterContainer");
    qmlRegisterAnonymousType<qqsfpm::FilterContainerAttached>(*_uri, _major);
    qmlRegisterUncreatableType<qqsfpm::FilterContainerFilter>(*_uri, _major, _minor, "FilterContainerFilter", "FilterContainerFilter is an abstract class");
    qmlRegisterType<qqsfpm::IndexFilter>(*_uri, _major, _minor, "IndexFilter");
    qmlRegisterType<qqsfpm::RangeFilter>(*_uri, _major, _minor, "RangeFilter");
    qmlRegisterType<qqsfpm::RegExpFilter>(*_uri, _major, _minor, "RegExpFilter");
    qmlRegisterUncreatableType<qqsfpm::RoleFilter>(*_uri, _major, _minor, "RoleFilter", "RoleFilter is an abstract class");
    qmlRegisterType<qqsfpm::ValueFilter>(*_uri, _major, _minor, "ValueFilter");

    qmlRegisterUncreatableType<qqsfpm::Sorter>(*_uri, _major, _minor, "Sorter", "Sorter is an abstract class");
    qmlRegisterInterface<qqsfpm::SorterContainer>("SorterContainer");
    qmlRegisterAnonymousType<qqsfpm::SorterContainerAttached>(*_uri, _major);
    qmlRegisterType<qqsfpm::RoleSorter>(*_uri, _major, _minor, "RoleSorter");
    qmlRegisterType<qqsfpm::StringSorter>(*_uri, _major, _minor, "StringSorter");
    qmlRegisterType<qqsfpm::FilterSorter>(*_uri, _major, _minor, "FilterSorter");
    qmlRegisterType<qqsfpm::ExpressionSorter>(*_uri, _major, _minor, "ExpressionSorter");

    qmlRegisterUncreatableType<qqsfpm::ProxyRole>(*_uri, _major, _minor, "ProxyRole", "ProxyRole is an abstract class");
    qmlRegisterInterface<qqsfpm::ProxyRoleContainer>("ProxyRoleContainer");
    qmlRegisterType<qqsfpm::JoinRole>(*_uri, _major, _minor, "JoinRole");
    qmlRegisterType<qqsfpm::SwitchRole>(*_uri, _major, _minor, "SwitchRole");
    qmlRegisterAnonymousType<qqsfpm::SwitchRoleAttached>(*_uri, _major);
    qmlRegisterType<qqsfpm::ExpressionRole>(*_uri, _major, _minor, "ExpressionRole");
    qmlRegisterType<qqsfpm::RegExpRole>(*_uri, _major, _minor, "RegExpRole");
    qmlRegisterType<qqsfpm::FilterRole>(*_uri, _major, _minor, "FilterRole");
}

static void Sfpm_registerTypes(const char* uri, const quint8 major, const quint8 minor)
{
    if(uri)
        _uri = &uri;
    _major = major;
    _minor = minor;
    Sfpm_registerTypes();
}

void qqsfpm::registerQmlTypes(const char* uri, const quint8 major, const quint8 minor)
{
    ::Sfpm_registerTypes(uri, major, minor);
}
