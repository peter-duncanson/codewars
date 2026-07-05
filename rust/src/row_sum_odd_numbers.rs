// Given the triangle of consecutive odd numbers:
//
//              1
//           3     5
//        7     9    11
//    13    15    17    19
// 21    23    25    27    29
// ...
//
// Calculate the sum of the numbers in the nth row of this 
// triangle (starting at index 1) e.g.: (Input --> Output)
// 1 -->  1
// 2 --> 3 + 5 = 8

// turns out the answer is just n^3 dang...

fn main() {
    // should be 74088
    let test = row_sum_odd_numbers(42);
    println!("{test}"); 
}

fn row_sum_odd_numbers(n: i64) -> i64 {
    let mut bounds: (i64, i64) = (1, 1);
    let mut count_rows: i64 = 0;
    let mut result: i64 = 0;
    loop {
        if count_rows == n { break (bounds.0, bounds.1); }
        else {
            bounds.0 += count_rows * 2;
            bounds.1 += (count_rows + 1) * 2;
            count_rows += 1;
        }
    };
    bounds.1 -= 2;
    for k in bounds.0..=bounds.1 {
        let x: i64 = k;
        if x % 2 != 0 { result += x; }
    }
    result
}
