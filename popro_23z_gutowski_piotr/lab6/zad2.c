#include <stdio.h>

/**
 * POPRO - Laboratorium 6. Zadanie 2.
 *
 * Zespół projektowy: Bartosz Bagiński, Krzysztof Dobosz, Piotr Gutowski
 */

struct Fuel {
	float distance;
	float volume;
	float performance;
};

typedef struct Fuel Fuel;

Fuel countPerformance(Fuel fuel);

void modifyPerformance(Fuel *fuel);

void kmToMiles(Fuel *fuel);

int main(void) {
	Fuel fuel;

	fuel.distance = 300.0;
	fuel.volume = 50.0;

	modifyPerformance(&fuel);

	fuel.distance = 600.0;
	Fuel sample = countPerformance(fuel);

	printf("\n%.2f\n", sample.performance);

	kmToMiles(&sample);
	printf("\n%.2f\n", sample.performance);

	return 0;
}

Fuel countPerformance(Fuel fuel) {
	fuel.performance = fuel.distance / fuel.volume;

	return fuel;
}

void modifyPerformance(Fuel *fuel) {
	fuel->performance = (fuel->distance) / (fuel->volume);
}

void kmToMiles(Fuel *fuel) {
	fuel->distance /= 1.6;
	fuel->volume /= 3.8;
	modifyPerformance(fuel);
}

