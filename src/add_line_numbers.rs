// Your team is writing a fancy new text editor and you've been tasked 
// with implementing the line numbering.
// Write a function which takes a list of strings and returns each 
// line prepended by the correct number.
// The numbering starts at 1. 
// The format is n: string. Notice the colon and space in between.
// Examples: (Input --> Output)
// [] --> []
// ["a", "b", "c"] --> ["1: a", "2: b", "3: c"]

fn main() {
    number(&["a", "b", "c"]);
}


fn number(lines: &[&str]) -> Vec<String> {
    let mut result: Vec<String> = vec![];
    let lines_iter = lines.into_iter().enumerate();
    for (i, n) in lines_iter {
        result.push(format!("{}: {}", i + 1, n));
    }
    result
}
