import java.math.BigInteger;

public class Task4 {
	public static void main(String[] args) {
		int[][] m = {
				{0, 1, 0, 0, 0, 1},
				{4, 0, 0, 3, 2, 0},
				{0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0}
		};
		int[] ans = Solution.solution(m);
		for(int i : ans) {
			System.out.print(i + " ");
		}
		System.out.println();
	}

	public static class Solution {
		public static int[] solution(int[][] m) {
			// Your code here
			int[] ans = Solver.solve(m);
			return ans;
		}

		private static long gcd(long a, long b) {
			if(b == 0) {
				return a;
			}
			return gcd(b, a % b);
		}

		static class Fraction {
			long num, den;

			private void normalize() {
				long gcdnd = gcd(num, den);
				while(gcdnd != 1) {
					num /= gcdnd;
					den /= gcdnd;
					gcdnd = gcd(num, den);
				}
			}

			Fraction() {
				this(0, 1);
			}

			Fraction(long nval) {
				this(nval, 1);
			}

			Fraction(long nval, long dval) {
				this.num = nval;
				this.den = dval;
				normalize();
			}

			static Fraction valueOf() {
				return new Fraction();
			}

			static Fraction valueOf(long nval) {
				return new Fraction(nval);
			}

			static Fraction valueOf(long nval, long dval) {
				return new Fraction(nval, dval);
			}

			Fraction add(Fraction f) {
				long nden = den * f.den;
				long nnum = num * f.den + f.num * den;
				return new Fraction(nnum, nden);
			}

			Fraction subtract(Fraction f) {
				long nden = den * f.den;
				long nnum = num * f.den - f.num * den;
				return new Fraction(nnum, nden);
			}

			Fraction multiply(Fraction f) {
				long nden = den * f.den;
				long nnum = num * f.num;
				return new Fraction(nnum, nden);
			}

			Fraction invert() {
				return new Fraction(den, num);
			}
		}

		static class Solver {
			static void printFractionMatrix(Fraction[][] matrix) {
				for(int i = 0; i < matrix.length; ++i) {
					for(int j = 0; j < matrix[i].length; ++j) {
						Fraction f = matrix[i][j];
						System.out.print("(" + f.num + "/" + f.den + ") ");
					}
					System.out.println();
				}
				System.out.println();
			}

			static Fraction getProbability(int i, int j, long[][] arr) {
				long num = arr[i][j], den = 0;
				for(int k = 0; k < arr[i].length; ++k) {
					den += arr[i][k];
				}
				return Fraction.valueOf(num, den);
			}

			static boolean[] findTerminalStates(long[][] arr) {
				int nstates = arr.length;
				boolean[] isTerminal = new boolean[nstates];
				for(int i = 0; i < nstates; ++i) {
					boolean transitioned = false;
					for(int j = 0; j < nstates; ++j) {
						if(arr[i][j] > 0) {
							transitioned = true;
							break;
						}
					}
					isTerminal[i] = !transitioned;
				}
				return isTerminal;
			}

			static Fraction[][] computeMarkovMatrix(long[][] arr, boolean[] isTerminal) {
				int nstates = arr.length;
				int[] order = new int[nstates];
				int fill = 0;
				for(int i = 0; i < nstates; ++i) {
					if(isTerminal[i]) {
						order[fill++] = i;
						arr[i][i] = 1;
					}
				}
				for(int i = 0; i < nstates; ++i) {
					if(!isTerminal[i]) {
						order[fill++] = i;
					}
				}
				Fraction[][] markovMatrix = new Fraction[nstates][nstates];
				for(int i = 0; i < nstates; ++i) {
					for(int j = 0; j < nstates; ++j) {
						markovMatrix[i][j] = getProbability(order[i], order[j], arr);
					}
				}
				return markovMatrix;
			}

			static Fraction[][] getCoFactor(Fraction[][] matrix, int p, int q) {
				int n = matrix.length;
				int i = 0, j = 0;
				Fraction[][] tmatrix = new Fraction[n-1][n-1];
				for(int row = 0; row < n; ++row) {
					for(int col = 0; col < n; ++col) {
						if(row != p && col != q) {
							tmatrix[i][j++] = matrix[row][col];
							if(j == n-1) {
								j = 0;
								i++;
							}
						}
					}
				}
				return tmatrix;
			}

			static Fraction[][] computeAdjointMatrix(Fraction[][] matrix) {
				int n = matrix.length;
				Fraction[][] adjointMatrix = new Fraction[n][n];
				if(n == 1) {
					adjointMatrix[0][0] = matrix[0][0];
					return adjointMatrix;
				}
				Fraction sign;
				for(int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						Fraction[][] tmatrix = getCoFactor(matrix, i, j);
						sign = ((i + j) % 2 == 0) ? Fraction.valueOf(1) : Fraction.valueOf(-1);
						adjointMatrix[j][i] = sign.multiply(computeDeterminant(tmatrix));
					}
				}
				return adjointMatrix;
			}

			static Fraction computeDeterminant(Fraction[][] matrix) {
				int n = matrix.length;
				Fraction determinant = Fraction.valueOf();
				if(n == 1) {
					return matrix[0][0];
				}
				Fraction sign = Fraction.valueOf(1);
				for(int f = 0; f < n; ++f) {
					Fraction[][] tmatrix = getCoFactor(matrix, 0, f);
					determinant = determinant.add(sign.multiply(matrix[0][f].multiply(computeDeterminant(tmatrix))));
					sign = sign.multiply(Fraction.valueOf(-1));
				}
				return determinant;
			}

			static void invertMatrix(Fraction[][] matrix) {
				Fraction determinant = computeDeterminant(matrix);
				if(determinant.num == 0) {
					throw new RuntimeException("determinant is zero!");
				}
				determinant = determinant.invert();
				Fraction[][] adjointMatrix = computeAdjointMatrix(matrix);
				for(int i = 0; i < matrix.length; ++i) {
					for(int j = 0; j < matrix[i].length; ++j) {
						matrix[i][j] = adjointMatrix[i][j].multiply(determinant);
					}
				}
			}

			static Fraction[][] multiplyMatrix(Fraction[][] matrix1, Fraction[][] matrix2) {
				int n1 = matrix1.length, n2 = matrix2.length;
				int m1 = matrix1[0].length, m2 = matrix2[0].length;
				if(n2 != m1) {
					throw new RuntimeException("invalid matrix multiplication!");
				}
				Fraction[][] matrix = new Fraction[n1][m2];
				for(int i = 0; i < n1; ++i) {
					for(int j = 0; j < m2; ++j) {
						Fraction fraction = Fraction.valueOf();
						for(int k = 0; k < matrix1[i].length; ++k) {
							fraction = fraction.add(matrix1[i][k].multiply(matrix2[k][j]));
						}
						matrix[i][j] = fraction;
					}
				}
				return matrix;
			}

			static Fraction[][] computeFMatrix(Fraction[][] QMatrix) {
				int n = QMatrix.length;
				Fraction[][] IQMatrix = new Fraction[n][n];
				for(int i = 0; i < IQMatrix.length; ++i) {
					for(int j = 0; j < IQMatrix[i].length; ++j) {
						if(i != j) {
							IQMatrix[i][j] = QMatrix[i][j].multiply(Fraction.valueOf(-1));
						} else {
							IQMatrix[i][j] = Fraction.valueOf(1).subtract(QMatrix[i][j]);
						}
					}
				}
				invertMatrix(IQMatrix);
				return IQMatrix;
			}

			static Fraction[][] computeLimitingMatrix(Fraction[][] markovMatrix, boolean[] isTerminal) {
				int nstates = markovMatrix.length;
				int ntstates = 0;
				for(int i = 0; i < nstates; ++i) {
					ntstates += isTerminal[i] ? 1 : 0;
				}
				Fraction[][] RMatrix = new Fraction[nstates-ntstates][ntstates];
				for(int i = ntstates; i < nstates; ++i) {
					for(int j = 0; j < ntstates; ++j) {
						RMatrix[i-ntstates][j] = markovMatrix[i][j];
					}
				}
				Fraction[][] QMatrix = new Fraction[nstates-ntstates][nstates-ntstates];
				for(int i = ntstates; i < nstates; ++i) {
					for(int j = ntstates; j < nstates; ++j) {
						QMatrix[i-ntstates][j-ntstates] = markovMatrix[i][j];
					}
				}
				Fraction[][] FMatrix = computeFMatrix(QMatrix);
				Fraction[][] limitingMatrix = multiplyMatrix(FMatrix, RMatrix);
				return limitingMatrix;
			}

			static int[] computeAnswer(Fraction[][] matrix) {
				int n = matrix[0].length;
				int[] ans = new int[n+1];
				long lcm = 1;
				for(int i = 0; i < n; ++i) {
					lcm = (lcm * matrix[0][i].den) / gcd(lcm, matrix[0][i].den);
				}
				for(int i = 0; i < n; ++i) {
					ans[i] = (int)(matrix[0][i].num * (lcm / matrix[0][i].den));
				}
				ans[n] = (int)lcm;
				return ans;
			}

			static int[] solve(int[][] m) {
				long[][] arr = new long[m.length][m[0].length];
				for(int i = 0; i < m.length; ++i) {
					for(int j = 0; j < m[i].length; ++j) {
						arr[i][j] = m[i][j];
					}
				}
				int[] ans;
				boolean[] isTerminal = findTerminalStates(arr);
				Fraction[][] markovMatrix = computeMarkovMatrix(arr, isTerminal);
				Fraction[][] limitingMatrix = computeLimitingMatrix(markovMatrix, isTerminal);
				ans = computeAnswer(limitingMatrix);
				return ans;
			}
		}
	}
}
