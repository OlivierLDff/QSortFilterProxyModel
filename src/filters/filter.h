#ifndef FILTER_H
#define FILTER_H

#include <QObject>
#include <qqmlsortfilterproxymodel_shared.h>

SFPM_NAMESPACE_START

class QQmlSortFilterProxyModel;

class SFPM_API_ Filter : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool enabled READ enabled WRITE setEnabled NOTIFY enabledChanged)
    Q_PROPERTY(bool inverted READ inverted WRITE setInverted NOTIFY invertedChanged)

public:
    explicit Filter(QObject *parent = nullptr);
    virtual ~Filter() = default;

    bool enabled() const;
    void setEnabled(bool enabled);

    bool inverted() const;
    void setInverted(bool inverted);

    bool filterAcceptsRow(const QModelIndex &sourceIndex, const QQmlSortFilterProxyModel& proxyModel) const;

    virtual void proxyModelCompleted(const QQmlSortFilterProxyModel& proxyModel);

Q_SIGNALS:
    void enabledChanged();
    void invertedChanged();
    void invalidated();

protected:
    virtual bool filterRow(const QModelIndex &sourceIndex, const QQmlSortFilterProxyModel& proxyModel) const = 0;
    void invalidate();

private:
    bool m_enabled = true;
    bool m_inverted = false;
};

SFPM_NAMESPACE_END

#endif // FILTER_H
