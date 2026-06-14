// Write a function that accepts a square matrix (N x N 2D array) and returns the determinant of the matrix.

fn main() {
    let det: i64 = determinant(&[vec![2, 5, 3], vec![1, -2, -1], vec![1, 3, 4]]);
    println!("The determinant of the matrix is: {det}");
    assert_eq!(det, -20, "Testing the determinant function");
}

fn determinant(matrix: &[Vec<i64>]) -> i64 {
    for i in 
}
