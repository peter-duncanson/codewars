struct BigNum {
    num: String,
}

trait Add_Big {
    fn add_big(&self) -> self
}

impl Add_Big for BigNum {

