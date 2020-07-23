/*
The structure of petrolPump is
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
int tour(petrolPump p[], int n) {
  int start = 0;
  int end = 1;
  int petrol = p[start].petrol - p[start].distance;

  while (petrol < 0 || start != end) {
    while (petrol < 0 && start != end) {
      petrol -= p[start].petrol - p[start].distance;
      start = (start + 1) % n;

      if (start == 0) {
        return -1;
      }
    }

    petrol += p[end].petrol - p[end].distance;
    end = (end + 1) % n;
  }

  return start;
}
