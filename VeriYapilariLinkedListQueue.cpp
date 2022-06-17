//191307012 BERK AKIN
#include <iostream>
#include <locale>
using namespace std;
struct kuyruk
{
	int değer;
	kuyruk* sonraki;
};
class Kuyruk
{
	kuyruk* ön;
	kuyruk* arka;
public:
	Kuyruk()
	{
		ön = NULL;
		arka = NULL;
	}
	void Yaz();
	void Ekle();
	void Sil();
};
void Kuyruk::Ekle()
{
	kuyruk* geçici = new kuyruk;
	geçici->sonraki = NULL;
	cout << "Kuyruğa eklenecek sayıyı girin." << endl;
	cin >> geçici->değer;
	if (arka == NULL)
	{
		arka = geçici;
		ön = geçici;
	}
	else
	{
		arka->sonraki = geçici;
		arka = geçici;
	}
}
void Kuyruk::Yaz()
{
	kuyruk* geçici = ön;
	cout << "Kuyruk Yazdırılıyor...\n";
	while (geçici != NULL)
	{
		cout << geçici->değer << endl;
		geçici = geçici->sonraki;
	}
}
void Kuyruk::Sil()
{
	if (ön != NULL)
	{
		kuyruk* geçici = ön;
		cout << "Silinecek Kuyruk Üyesi: " << ön->değer << endl;
		ön = ön->sonraki;
		delete geçici;
		if (ön == NULL)
		{
			cout << "Tüm Üyeler Silindi" << endl;
			arka == NULL;
		}
	}
	else
	{
		cout << "Kuyruk Boş,Silinebilecek Eleman Yok" << endl;
	}
}
int main()
{
	setlocale(LC_ALL, "Turkish");
	Kuyruk Yeni_Kuyruk;
	int işlem;
	do
	{
		cout << "Yapılmak İstenen İşlemi Seçin\n(1)Ekleme\n(2)Silme\n(3)Yazdırma\n(4)Çıkış" << endl;
		cin >> işlem;
		if (işlem == 1)
		{
			Yeni_Kuyruk.Ekle();
		}
		else if (işlem == 2)
		{
			Yeni_Kuyruk.Sil();
		}
		else if (işlem == 3)
		{
			Yeni_Kuyruk.Yaz();
		}
		else if (işlem == 4)
		{
			cout << "Çıkış Yapılıyor" << endl;
		}
		else
		{
			cout << "Yanlış İşlem Numarası Seçildi." << endl;
		}
	} while (işlem != 4);
	return 41;
}

