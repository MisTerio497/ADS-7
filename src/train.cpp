// Copyright 2022 NNTU-CS
#include "../include/train.h"
Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
  Car *newCar = new Car(light);
  if (!first) {
    first = newCar;
    first->next = first;
    first->prev = first;
  } else {
    Car *tail = first->prev;
    tail->next = newCar;
    newCar->prev = tail;
    newCar->next = first;
    first->prev = newCar;
  }
}

int Train::getLength() {
  first->light = true;
  Car *current = first->next;

  while (true) {
    int lenght = 1;
    countOp++;
    while (!current->light) {
      current = current->next;
      countOp++;
      lenght++;
    }
    current->light = false;

    for (int i = 0; i < lenght; i++) {
      current = current->prev;
      countOp++;
    }

    if (!current->light) {
      return lenght;
    }
    current = current->next;
  }
}

int Train::getOpCount() { return countOp; }
