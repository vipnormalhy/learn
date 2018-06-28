namespace Delegate.EventTest {
	class CarEventArgs: System.EventArgs {
		public int CarType {get; private set;}

		public CarEventArgs(int car_type) {
			System.Console.WriteLine("Create event args");

			CarType = car_type;
		}
	}

	class CarDeal {
		// EventHandler edition
		public event System.EventHandler<CarEventArgs> CarProduceEvent;
		
		// delegate edition
		// public delegate void CarProduceDelegate(object sender, CarEventArgs args);
		// public event CarProduceDelegate CarProduceEvent;

		public void ProduceCar(int type) {
			int car_type = type;
			System.Console.WriteLine($"Produce one car, type is {car_type}");

			CarProduceEvent?.Invoke(this, new CarEventArgs(car_type));
		}

		public void ConsumeCar(object sender, CarEventArgs args) {
			int car_type = args.CarType;
			System.Console.WriteLine($"Consume one car, type is {car_type}");
		}

		public void Test() {
			CarProduceEvent += ConsumeCar;	

			for (int i = 0; i < 10; i++) {
				ProduceCar(i);
			}
		}
	}
}
