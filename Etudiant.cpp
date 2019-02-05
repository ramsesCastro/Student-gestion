#include "Etudiant.h"


//constructeur par défaut
CEtudiant::CEtudiant()
	: m_pNom(NULL)
	, m_Numero(0)
	, m_Nb_notes(0)
	, m_pNotes(NULL)
	, m_Moyenne(0)
{
}

//destructeur
CEtudiant::~CEtudiant()
{
	if (m_pNom != NULL) delete[]m_pNom; 
	m_pNom = NULL;
}


// Calcul de la moyenne
double CEtudiant::Moyenne()
{
	//Caluler la moyenne
	for (int i = 0; i < m_Nb_notes; i++)
	{
		m_Moyenne += m_pNotes[i];
	}
	m_Moyenne /= m_Nb_notes;
	return m_Moyenne;
}


CEtudiant::CEtudiant(char* nom, int numero, int nombre_notes)
{
	m_pNom = new char[strlen(nom) + 1];
	strcpy_s(m_pNom, strlen(nom) + 1, nom);

	m_Numero = numero;

	m_Nb_notes = nombre_notes;

}

istream& operator >> (istream& is, CEtudiant& E)
{
	
	cout << "Saisir les informations de l'etudiant." << endl;
	cout << "Entrer son nom." << endl;
	
	char* temp; temp = new char[100];
	is >> temp;

	E.m_pNom = new char[strlen(temp) + 1];
	strcpy_s(E.m_pNom, strlen(temp) + 1, temp);
	cout << "Entrer son numero." << endl;
	is >> E.m_Numero;
	cout << "Entrer le nombre de notes." << endl;
	is >> E.m_Nb_notes;

	E.m_pNotes = new double[E.m_Nb_notes];
	for (int i = 0; i < E.m_Nb_notes; i++)
	{
		cout << "Saisir la note n°" << i + 1 << endl;
		is >> E.m_pNotes[i];
	}


	return is;
}

ostream& operator << (ostream& os, CEtudiant& E)
{
	cout << "Les informations de l'etudiant sont: " << endl;
	os << "Son nom est :" << E.m_pNom << endl;
	os << "Son numéro est :" << E.m_Numero << endl;
	os << "Ses notes sont au nombre de :" << E.m_Nb_notes << endl;
	for (int i = 0; i < E.m_Nb_notes; i++)
	{
		os << "La note numero " << i + 1 << " = " << E.m_pNotes[i] << endl;
	}
	os << "Sa moyenne est de : " << E.Moyenne() << endl;
	return os;
}
