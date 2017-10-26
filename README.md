# For-Range
Simple and fast class, to use the range in the range-based loop.
 
# [![Codacy Badge](https://api.codacy.com/project/badge/Grade/351a0ed3a1674d098d4b982f3695eaf9)](https://www.codacy.com/app/yeswell/For-Range?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=yeswell/For-Range&amp;utm_campaign=Badge_Grade)

**Contents:**
1. [Examples of usage](#example)
2. [Speed](#speed)

<a name="example"> **Examples of usage** </a>

1. Use with one argument:
<table>
<tr>
<td>
    
```cpp
for (auto i: range(5))
{
    cout << i << " ";
}

// 1 2 3 4 5
```

</td>    
<td>
    
```cpp
for (auto i: range_z(5))
{
    cout << i << " ";
}

// 0 1 2 3 4
```

</td>
</tr>
</table>

2. Use with two arguments:

<table>
<tr>
<td>
    
```cpp
for (auto i: range(3, 7))
{
    cout << i << " ";
}

// 3 4 5 6 7
```

</td>
</tr>
</table>

3. Use with three arguments:

<table>
<tr>
<td>    
    
```cpp
for (auto i: range(0, 9, 2))
{
    cout << i << " ";
}

// 0 2 4 6 8
```

</td>    
<td>

```cpp
for (auto i: range(9, 0, -2))
{
    cout << i << " ";
}

// 9 7 5 3 1
```

</td>
</tr>
</table>


<a name="speed"> **Speed** </a>
