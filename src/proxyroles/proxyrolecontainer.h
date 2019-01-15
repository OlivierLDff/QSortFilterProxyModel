#ifndef PROXYROLECONTAINER_H
#define PROXYROLECONTAINER_H

#include <QList>
#include <QQmlListProperty>
#include <qqmlsortfilterproxymodel_shared.h>

SFPM_NAMESPACE_START

class ProxyRole;
class QQmlSortFilterProxyModel;

class SFPM_API_ ProxyRoleContainer {
public:
    virtual ~ProxyRoleContainer();

    QList<ProxyRole*> proxyRoles() const;
    void appendProxyRole(ProxyRole* proxyRole);
    void removeProxyRole(ProxyRole* proxyRole);
    void clearProxyRoles();

    QQmlListProperty<ProxyRole> proxyRolesListProperty();

protected:
    QList<ProxyRole*> m_proxyRoles;

private:
    virtual void onProxyRoleAppended(ProxyRole* proxyRole) = 0;
    virtual void onProxyRoleRemoved(ProxyRole* proxyRole) = 0;
    virtual void onProxyRolesCleared() = 0;

    static void append_proxyRole(QQmlListProperty<ProxyRole>* list, ProxyRole* proxyRole);
    static int count_proxyRole(QQmlListProperty<ProxyRole>* list);
    static ProxyRole* at_proxyRole(QQmlListProperty<ProxyRole>* list, int index);
    static void clear_proxyRoles(QQmlListProperty<ProxyRole>* list);
};

SFPM_NAMESPACE_END

#define ProxyRoleContainer_iid SFPM_NAMESPACE_IID ".ProxyRoleContainer"
Q_DECLARE_INTERFACE(SFPM_NAMESPACE::ProxyRoleContainer, ProxyRoleContainer_iid)

#endif // PROXYROLECONTAINER_H
