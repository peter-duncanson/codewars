fn main() {
    let test: u64 = square_digits(3212);
    println!("{test}");
}

//nice
// fn square_digits(mut num: u64) -> u64 {
//     let mut res = 0;
//     let mut mul = 1;
//     while num != 0 {
//         let m = if num % 10 < 4 { 10 } else { 100 };
//         res += (num % 10).pow(2) * mul;
//         mul *= m;
//         num /= 10;
//     }
//     res
// }

fn square_digits(num: u64) -> u64 {
    let get_size = |x: u64| -> u64 {
        let mut divisor: u64 = 10;
        let mut size: u64 = 1;
        loop {
            let check_size: u64 = x / divisor;
            if check_size == 0  { break size; } 
            else {
                divisor *= 10;
                size += 1;
            }
        }
    };
    let split_into_digits = |number: u64, size_of_number: u64| -> Vec<u64> {
        let mut digit_vector = Vec::new();
        for i in 1..=size_of_number {
            let lower: u64 = (10 as u64).pow((i - 1).try_into().unwrap());
            let higher: u64 = (10 as u64).pow(i.try_into().unwrap());
            digit_vector.push(((number % higher) - (number % lower)) / lower);
        }
        digit_vector.reverse();
        digit_vector
    };
    let num_size: u64 = get_size(num);
    let digits: Vec<u64> = split_into_digits(num, num_size);
    let mut result_size: u64 = 0;
    for digit in digits.iter() {
        if *digit > 3 { result_size += 2; }
        else { result_size += 1; }
    }
    let mut result: u64 = 0;
    for i in 0..digits.len() {
        let square: u64 = digits[i].pow(2);
        result_size -= get_size(square);
        result += square * (10 as u64).pow(result_size.try_into().unwrap());
    };
    return result;
}
