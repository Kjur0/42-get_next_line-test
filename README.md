*This project has been created as part of the 42 curriculum by **kjurkows***

# `ft_get_next_line-test`

**IT IS NOT NORM COMPLIANT**

## Description

`ft_get_next_line-test` is a testing suite for `get_next_line` (`gnl`). Used for testing against `gnl` subject using `gtest`(Google Test).

See [Detailed description](#detailed-description) for list of tests.

## Instructions

### Before testing

1. clone your `gnt` into `get_next_line` folder

### Testing mandatory part

```shell
./test.sh
```

### Testing bonus part

```shell
./test.sh bonus
```

## Resources

* `gnl` subject
* [Lorem Ipsum generator](https://lipsum.com/)

### AI Usage

No AI tools were used in the creation of this project.

## Detailed description

Bellow is the list of all tests:

### Norminette

| Name    | Description  |
|---------|--------------|
| `norme` | `norminette` |


### Assets

Assets tests use `*.txt` files from `assets` folder to test `gnl` against them. Each file has different content and is used to test different scenarios.

| Name        | Description                       | File                                      |
|-------------|-----------------------------------|-------------------------------------------|
| `empty`     | Empty file                        | [`empty.txt`](./assets/empty.txt)         |
| `nl`        | File with only new line           | [`nl.txt`](./assets/nl.txt)               |
| `space`     | File with only space              | [`space.txt`](./assets/space.txt)         |
| `space_nl`  | File with only space and new line | [`space_nl.txt`](./assets/space_nl.txt)   |
| `2line`     | File with two lines               | [`2line.txt`](./assets/2line.txt)         |
| `long_line` | about 1000 `\|`                   | [`long_line.txt`](./assets/long_line.txt) |
| `lorem`     | 5 lines of lorem ipsum            | [`lorem.txt`](./assets/lorem.txt)         |
| `lipsum`    | 20 lines of lorem ipsum           | [`lipsum.txt`](./assets/lipsum.txt)       |
