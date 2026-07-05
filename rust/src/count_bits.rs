// Write a function that takes an integer as input, and returns 
// the number of bits that are equal to one in the binary 
// representation of that number. You can guarantee that input 
// is non-negative.
// Example: The binary representation of 1234 is 10011010010, 
// so the function should return 5 in this case

fn main() {
    count_bits(4);
}

fn count_bits(mut n: i64) -> u32 {
    let mut result: u32 = 0;
    loop {
        if n % 2 == 1 { result += 1; }
        n /= 2;
        if n == 0 { break result; }
    };
    result
}
