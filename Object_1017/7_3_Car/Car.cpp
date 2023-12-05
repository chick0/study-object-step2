#include <iostream>

using namespace std;

class Car {
private:
	int gasolineGauge;
public:
	Car(int g) {
		gasolineGauge = g;
	}

	int GetGasGauge() {
		return gasolineGauge;
	}
};

class HybridCar : public Car {
private:
	int electricGauge;
public:
	HybridCar(int g, int e) : Car(g) {
		electricGauge = e;
	}

	int GetElecGauge() {
		return electricGauge;
	}
};

class HybridWaterCar : public HybridCar {
private:
	int waterGauge;
public:
	HybridWaterCar(const int gas, const int elec, const int water) : HybridCar(gas, elec) {
		waterGauge = water;
	}

	int GetWaterGauge() {
		return waterGauge;
	}

	void ShowCurrentGauge() {
		cout << "ÀÜ¿© °¡¼Ö¸° : " << GetGasGauge() << endl;
		cout << "ÀÜ¿© Àü±â·® : " << GetElecGauge() << endl;
		cout << "ÀÜ¿© ¿öÅÍ·® : " << GetWaterGauge() << endl;
	}
};

int main() {
	HybridWaterCar hbCar(79, 65, 34);
	hbCar.ShowCurrentGauge();

	return 0;
}
