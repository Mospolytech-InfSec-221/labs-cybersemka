#include "serverfunctions.h"

QString processClientMessage(const QString& message, QMap<QString, QString>& authCodes, QString& lastLogin)
{
    QStringList parts = message.split(";");
    QString response;

    if (parts.size() >= 3) {
        if (parts.at(0) == "auth" && parts.at(3) == authCodes.value(parts.at(1))) {
            response = "auth+";
            lastLogin = parts.at(1);

            // Записать в конец файла логов
            QFile file("logs.txt");
            if (file.open(QIODevice::Append | QIODevice::Text)) {
                QTextStream out(&file);
                out << "auth: " << lastLogin << endl;
                file.close();
            }
        } else {
            response = "auth-";
        }
    } else {
        response = "auth-";
    }

    // Генерировать новый код авторизации
    authCodes.insert(parts.at(1), QString::number(qrand()));
    return "code:" + authCodes.value(parts.at(1));
}
