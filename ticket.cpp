#include "ticket.h"
#include"mainwindow.h"

Ticket::Ticket()
{
    id=0;
    horaire_entr=0;
    horaire_arr=0;
    num_mat=0;
    prix=0;
}

Ticket::Ticket(int id,int entr,int arr,int mat,float p)
{
    this->id=id;
    this->horaire_entr=entr;
    this->horaire_arr=arr;
    this->num_mat=mat;
    this->prix=p;
}
int Ticket::getid(){return id;}
int Ticket::gethoraire_entr(){return horaire_entr;}
int Ticket::gethoraire_arr(){return horaire_arr;}
int Ticket::getnum_mat(){return num_mat;}
float Ticket::getprix(){return prix;}
void Ticket::setid(int id){this->id=id;}
void Ticket::sethoraire_entr(int entr){this->horaire_entr=entr;}
void Ticket::sethoraire_arr(int arr){this->horaire_arr=arr;}
void Ticket::setnum_mat(int mat){this->num_mat=mat;}
void Ticket::setprix(float p){this->prix=p;}

bool Ticket::ajouter()
{
    QSqlQuery query;
    QString id_string=QString::number(id);
    QString prix_string=QString::number(prix);
    QString horaire_entr_string=QString::number(horaire_entr);
    QString horaire_arr_string=QString::number(horaire_arr);
    QString num_mat_string=QString::number(num_mat);

    query.prepare("insert into tickets(id,horaire_entr,horaire_arr,num_mat,prix) values (:id,:horaire_entr,:horaire_arr,:num_mat,:prix)");

    //Création des variables liées
    query.bindValue(0,  id_string);  //faire la correspondance
    query.bindValue(1,  horaire_entr);
    query.bindValue(2,  horaire_arr);
    query.bindValue(3,  num_mat);
    query.bindValue(4,  prix_string);

    return query.exec(); //exec() envoie la requete pour l'executer
}

QSqlQueryModel * Ticket::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    //remplir tab
    //QSqlQueryModel : reading from SQL

              model->setQuery("SELECT* FROM tickets");
              model->setHeaderData(0, Qt::Horizontal, QObject::tr("id")); // ajouter nom colon
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("horaire_entr"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("horaire_arr"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("num_mat"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));
        return model;
}

bool Ticket::supprimer(int id)
{
    QSqlQuery query;
              query.prepare("Delete from tickets where id=:id");

              query.bindValue(0, id);

              query.exec();
}

bool Ticket::modifier()
{

    QSqlQuery query;
    QString id_string=QString::number(id);
    QString prix_string=QString::number(prix);
    QString horaire_entr_string=QString::number(horaire_entr);
    QString horaire_arr_string=QString::number(horaire_arr);
    QString num_mat_string=QString::number(num_mat);
        query.prepare("UPDATE tickets SET id=:id,horaire_entr=:horaire_entr,horaire_arr=:horaire_arr,num_mat=:num_mat,prix=:prix WHERE id=:id ");
        query.bindValue(":id",id_string); //liasion valeur/parametre
        query.bindValue(":horaire_entr", horaire_entr_string);
        query.bindValue(":horaire_arr", horaire_arr_string);
        query.bindValue(":num_mat", num_mat_string);
        query.bindValue(":prix", prix_string);
        query.exec();

}
