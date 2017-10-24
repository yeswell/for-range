---
# For-Range
## Simple and fast class, to use the range in the range-based loop.


[![Codacy Badge](https://api.codacy.com/project/badge/Grade/351a0ed3a1674d098d4b982f3695eaf9)](https://www.codacy.com/app/yeswell/For-Range?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=yeswell/For-Range&amp;utm_campaign=Badge_Grade)

---

Examples of usage

```cpp
for (auto i: range(5))
{
    cout << i << " ";
}

// 1 2 3 4 5
```

```cpp
for (auto i: range_z(5))
{
    cout << i << " ";
}

// 0 1 2 3 4
```

```cpp
for (auto i: range(3, 7))
{
    cout << i << " ";
}

// 3 4 5 6 7
```

```cpp
for (auto i: range(2, 9, 3))
{
    cout << i << " ";
}

// 2 5 8
```

```cpp
for (auto i: range(9, 2, -3))
{
    cout << i << " ";
}

// 9 6 3
```
