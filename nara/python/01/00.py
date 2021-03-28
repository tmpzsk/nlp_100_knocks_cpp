def reverse_s(forward_string: str) -> str:
    r_s = ""
    for i in s:
        r_s = i + r_s
    return r_s


if __name__ == "__main__":
    s = "stressed"
    rev_s = reverse_s(s)
    print(rev_s)

