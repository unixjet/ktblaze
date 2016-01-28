#ifndef BLAZE
#define BLAZE

#include <QAbstractEventDispatcher>
#include "Core/Object.h"

class Blaze;

class MsgTrigger : public QObject
{
    Q_OBJECT
public:
    MsgTrigger(Urho3D::WeakPtr<Blaze> blaze, QObject* parent = 0);
    virtual ~MsgTrigger();

    void Trigger();

protected:
    void timerEvent(QTimerEvent *);

    int timerId_;
    Urho3D::WeakPtr<Blaze> blaze_;
};

class Blaze : public Urho3D::Object  //, public QAbstractEventDispatcher
{

    friend class MsgTrigger;
    URHO3D_OBJECT(Blaze, Object);

public:
    Blaze(Urho3D::Context* context);
    virtual ~Blaze();

protected:
    void ProcessEvents();

#if 0
    bool processEvents(QEventLoop::ProcessEventsFlags flags) override;
    bool hasPendingEvents()  // ### Qt6: remove, mark final or make protected
    {
        return qEventDispatcher_->hasPendingEvents();
    }

    void registerSocketNotifier(QSocketNotifier *notifier)
    {
        qEventDispatcher_->registerSocketNotifier(notifier);
    }

    void unregisterSocketNotifier(QSocketNotifier *notifier)
    {
        qEventDispatcher_->unregisterSocketNotifier(notifier);
    }

#if QT_DEPRECATED_SINCE(5,0)
    QT_DEPRECATED inline int registerTimer(int interval, QObject *object)
    { return  qEventDispatcher_->registerTimer(interval, object);}
    QT_DEPRECATED inline void registerTimer(int timerId, int interval, QObject *object)
    { qEventDispatcher_->registerTimer(timerId, interval, object); }
#endif
//    int registerTimer(int interval, Qt::TimerType timerType, QObject *object);
    void registerTimer(int timerId, int interval, Qt::TimerType timerType, QObject *object)
    {
        qEventDispatcher_->registerTimer(timerId, interval, timerType, object);
    }

    bool unregisterTimer(int timerId)
    {
        return qEventDispatcher_->unregisterTimer(timerId);
    }

    bool unregisterTimers(QObject *object)
    {
         return qEventDispatcher_->unregisterTimers(object);
    }

    QList<TimerInfo> registeredTimers(QObject *object) const
    {
         return qEventDispatcher_->registeredTimers(object);
    }

    int remainingTime(int timerId)
    {
        return qEventDispatcher_->remainingTime(timerId);
    }

#ifdef Q_OS_WIN
    bool registerEventNotifier(QWinEventNotifier *notifier)
    {
        return qEventDispatcher_->registerEventNotifier(notifier);
    }

    void unregisterEventNotifier(QWinEventNotifier *notifier)
    {
        qEventDispatcher_->unregisterEventNotifier(notifier);
    }

#endif

    void wakeUp()
    {
        qEventDispatcher_->wakeUp();
    }

    void interrupt()
    {
        qEventDispatcher_->interrupt();
    }

    void flush()
    {
        qEventDispatcher_->flush();
    }

    void startingUp()
    {
        qEventDispatcher_->startingUp();
    }

    void closingDown()
    {
        qEventDispatcher_->closingDown();
    }

private:
    QAbstractEventDispatcher * qEventDispatcher_;
#endif

};

#endif // BLAZE

