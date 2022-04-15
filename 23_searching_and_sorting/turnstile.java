static class Person {
	int id;
	int time;
	Person(int id, int time) {
		this.id = id;
		this.time = time;
	}
}
public int[] getTimes(int[] times, int[] directions) {
	int[] res = new int[times.length];
	// initialize to exit (default)
	int lastDir = 1;
	int timeStamp = 0;
	PriorityQueue enterQueue = new PriorityQueue<>((o1, o2) -> o1.time == o2.time ? o1.id - o2.id : o1.time - o2.time);
	PriorityQueue exitQueue = new PriorityQueue<>((o1, o2) -> o1.time == o2.time ? o1.id - o2.id : o1.time - o2.time);
	for (int i = 0; i < times.length; i ++) {
		if (directions[i] == 1) {
			exitQueue.offer(new Person(i, times[i]));
		} else {
			enterQueue.offer(new Person(i, times[i]));
		}
	}
	while (!(enterQueue.isEmpty() && exitQueue.isEmpty())) {
		int nextEnterTime = enterQueue.isEmpty() ? Integer.MAX_VALUE : enterQueue.peek().time;
		int nextExitTime = exitQueue.isEmpty() ? Integer.MAX_VALUE : exitQueue.peek().time;
		if (nextEnterTime > timeStamp && nextExitTime > timeStamp) {
			lastDir = 1;
			timeStamp = Math.min(nextEnterTime, nextExitTime);
			continue;

		} else if (nextEnterTime <= timeStamp && nextExitTime <= timeStamp) {
			// direction does not change here, no need to update lastDir
			Person person = lastDir == 1 ? exitQueue.poll() : enterQueue.poll();
			res[person.id] = timeStamp;
		} else {
			Person person;
			if (nextEnterTime <= timeStamp) {
				person = enterQueue.poll();
				lastDir = 0;
			} else {
				person = exitQueue.poll();
				lastDir = 1;
			}
			res[person.id] = timeStamp;
		}
		timeStamp++;
	}
	return res;
}