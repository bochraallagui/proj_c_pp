#include "connection.h"
//test Tutoriel Git
Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test-bd");
db.setUserName("sami");//inserer nom de l'utilisateur
db.setPassword("sami");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
