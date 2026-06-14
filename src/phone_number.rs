// Write a function that accepts an array of 10 integers 
// (between 0 and 9), that returns a string of those 
// numbers in the form of a phone number.

fn main() {
    let arr1: [u8; 10] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 0];
    let test = String::from(format!("({}{}{}) {}{}{}-{}{}{}{}", arr1.iter()));
    
    println!("Here -> ***{}***", test);
    // let test1: bool = assert_eq!(create_phone_number(&[1, 2, 3, 4, 5, 6, 7, 8, 9, 0]), "(123) 456-7890");
    // let test2: bool = assert_eq!(create_phone_number(&[1, 1, 1, 1, 1, 1, 1, 1, 1, 1]), "(111) 111-1111");
    // let test3: bool = assert_eq!(create_phone_number(&[1, 2, 3, 4, 5, 6, 7, 8, 9, 9]), "(123) 456-7899");
}

// fn create_phone_number(numbers: &[u8]) -> String {
//
// }

// fn test_array() -> String {
//     let mut out = String::new();
//     let arr: [u8; 5] = [1, 2, 3, 4, 5];
//     for i in arr {
//         println!{"{i}"};
//     }
//     out.push(arr[1] as char);
//     out
// }
