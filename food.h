#ifndef FOOD_H
#define FOOD_H

#include <QObject>

class Food : public QObject
{
    Q_OBJECT
    QString m_name;
    unsigned int m_calories, m_carb, m_protein, m_fat;
public:
    explicit Food();

    void setName(QString name){
        m_name = name;
    }
    QString name() const{
        return m_name;
    }

    void setCalories(unsigned int calories){
        m_calories = calories;
    }
    unsigned int calories() const{
        return m_calories;
    }

    void setCarb(unsigned int carb){
        m_carb = carb;
    }
    unsigned int carb() const{
        return m_carb;
    }

    void setProtein(unsigned int protein){
        m_protein = protein;
    }
    unsigned int protein() const{
        return m_protein;
    }

    void setFat(unsigned int fat){
        m_fat = fat;
    }
    unsigned int fat() const{
        return m_fat;
    }

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(unsigned int calories READ calories WRITE caloriesName NOTIFY caloriesChanged)
    Q_PROPERTY(unsigned int carb READ carb WRITE carbName NOTIFY carbChanged)
    Q_PROPERTY(unsigned int protein READ protein WRITE setProtein NOTIFY proteinChanged)
    Q_PROPERTY(unsigned int fat READ fat WRITE setFat NOTIFY fatChanged)

signals:
    void nameChanged();
    void caloriesChanged();
    void carbChanged();
    void proteinChanged();
    void fatChanged();

public slots:
};

#endif // FOOD_H
