fn likes(names: &[&str]) -> String {
    let result: String = match names.len() {
        0 => 
            String::from("no one likes this"),
        1 => 
            format!("{} likes this", &names[0].to_owned()),
        2 => 
            format!("{} and {} like this", &names[0].to_owned(), &names[1]),
        3 => 
            format!("{}, {} and {} like this", &names[0].to_owned(), &names[1], &names[2]),
        _ =>
            format!("{}, {} and {} others like this", &names[0].to_owned(), &names[1], &names.len() - 2),
    };
    result
}
