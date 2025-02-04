#ifndef AudioSource_H
#define AudioSource_H
#include <QtCore/QObject>
#include <QtCharts/QAbstractSeries>
#include <QtCharts/QXYSeries>
#include <QtCore/QIODevice>
#include <vector>

QT_BEGIN_NAMESPACE
class QQuickView;
QT_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class AudioSource : public QIODevice
{
    Q_OBJECT
public:
    explicit AudioSource(QObject *parent = 0);
    Q_INVOKABLE void setSeries(QAbstractSeries *series);
    double calculateAmplitude(const char *data, qint64 maxSize);

signals:
    void amplitudeChanged(double amplitude); // new signal

protected:
    qint64 readData(char * data, qint64 maxSize);
    qint64 writeData(const char * data, qint64 maxSize);

private:
    QXYSeries *m_series;

    
};


#endif // AudioSource_H
