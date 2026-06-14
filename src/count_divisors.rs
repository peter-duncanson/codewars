// Create a function named divisors/Divisors that takes an integer 
// n > 1 and returns an array with all of the integer's divisors
// (except for 1 and the number itself), from smallest to largest. 
// If the number is prime return the string "(integer) is prime"
// Use Result<Vec<u32>, String> in Rust.
// Examples:
//
// divisors(12) --> [2, 3, 4, 6]
// divisors(25) --> [5]
// divisors(13) --> "13 is prime"

fn main() {
    let _test = divisors(15);
}

fn divisors(integer: u32) -> Result<Vec<u32>, String> {
    let mut ans: Vec<u32> = Vec::new();
    for k in 2..integer {
        if integer % k == 0 {
            ans.push(k);
        }
    }
    match ans.len() {
        0 => Err(format!("{integer} is prime")),
        _ => Ok(ans),
    }
}
