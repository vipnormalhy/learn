using System;


namespace GenericTest.Convariance {
	public enum ShapeType {
		Rectangle,
		Square,
		Triangle,
	}

	abstract public class Shape: ILengthable<Shape>, /* IConvariance<Shape> */ {
		public ShapeType Type_ {get; protected set;}

		public int CalculateLength(Shape item) {
			return 0;
		}
	}

	public class Rectangle: Shape, ILengthable<Rectangle> /* IConvariance<Rectangle> */{
		public Rectangle() {
			Type_ = ShapeType.Rectangle;
		}

		public int CalculateLength(Rectangle item) {
			return 0;
		}
	}

	public class Square: Rectangle, ILengthable<Square>, IConvariance<Square> {
		public Square() {
			Type_ = ShapeType.Square;
		}

		public int CalculateLength(Square item) {
			return 0;
		}

		public Square TestConvariance() {
			return null;
		}
	}

	public interface ILengthable<in T> {
		int CalculateLength(T item);
	}

	public interface IConvariance<out T> {
		T TestConvariance();
	}

	class ConvarianceTest {
		public void ConvarianceTestMain() {
			Rectangle rec = new Rectangle();
			Shape shape = ConvarianceTestReturnRectangle(rec);

			ILengthable<Square> lengthable = new Rectangle();
			IConvariance<Shape> convariance_test = new Square();
		}

		public Rectangle ConvarianceTestReturnRectangle(Shape shape) {
			Rectangle rec = new Rectangle();
			return rec;
		}
	}
}
