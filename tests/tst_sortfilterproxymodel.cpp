#include <QtQuickTest>
#include <QQmlEngine>
#include <QQmlContext>

#include <SortFilterProxyModel/SortFilterProxyModel.hpp>
#include <indexsorter.h>
#include <testroles.h>

class Setup : public QObject
{
    Q_OBJECT

public:
    Setup() {}

public slots:
    void qmlEngineAvailable(QQmlEngine *engine)
    {
        qqsfpm::registerQmlTypes();
        registerIndexSorterTypes();
        registerTestRolesTypes();
    }
};

QUICK_TEST_MAIN_WITH_SETUP(tst_sortfilterproxymodel, Setup)

#include "tst_sortfilterproxymodel.moc"
