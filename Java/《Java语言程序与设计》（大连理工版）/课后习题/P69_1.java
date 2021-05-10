package 程序实践题;

class Juxing{
	public int length;
	public int weigth;
	public Juxing(int obLength,int obWeigth) {
		length=obLength;
		weigth=obWeigth;
	}
	public void setLength(int lLength) {
		length=lLength;
	}
	public int getLength() {
		return length;
	}
	public void setWeigth(int wWeigth) {
		weigth=wWeigth;
	}
	public int getWeigth() {
		return weigth;
	}
	public int findArea() {
		return length*weigth;
	}
}
class Changfangti extends Juxing{
	private int heigth;
	public Changfangti(int obLength,int obWeigth,int obHeigth) {
		super(obLength,obWeigth);
		heigth=obHeigth;
	}
	public void setHeigth(int hHeigth) {
		heigth=hHeigth;
	}
	public int getHeigth() {
		return heigth;
	}
	public int findVolume() {
		return length*weigth*heigth;
	}
}

public class  P69_1 {
	public static void main(String[] args) {
		Juxing j1=new Juxing(2,5);
		System.out.println("该矩形的面积为："+j1.findArea());
		Changfangti c1=new Changfangti(2,5,7);
		System.out.println("该长方体的体积为："+c1.findVolume());
		}
}

