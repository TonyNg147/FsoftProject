

# [Góp ý]

***

## 1. Branch:

* Các branch rác thì @Nguyen xóa hết đi nhé.
* Mỗi người sẽ được tạo một **branch riêng** và làm việc trên chính branch của mình như sau:
    * `add`, `commit`, `push` source code lên **branch cá nhân**.
	* **Branch master** chỉ dùng để `pull` code về **local**. **Branch master** sẽ do LEAD quản lý.



## 2. Coding style:
* Để tránh nhiễu loạn code, à không nói gọn là đỡ ***lú*** khi `merge` code vào **master** :)).

> => Mọi người nên thống nhất coding style cơ bản chung.
* Ví dụ:

```js
    void codingStyle () {
        // code here
    }

    // hay

    void codingStyle ()
    {
        // code here
    }
```

Hoặc

```js
    if (x == 3) {
        // code here
    } else {
        // code here
    }

    // hay

    if ( x == 3 )
    {
        // code here
    }
    else
    {
        // code here
    }
```

* Vân vân và mây mây.

> ==> Có thể setting chung format trong VS.


## Sử dụng git command:
Mình có một số tips như sau: `(Giả sử mình có branch cá nhân là: phulh1)`
1. Khi bắt đầu một ngày làm việc mới. Bạn phải `pull` code từ **master** về **local**.
    * Lý do:
        * Làm việc độc lập, bạn không biết khi nào các dev trong team `push` code
        * => nên trong team luôn phải update code. Để khi `push` lên lại không bị **conflict**.
    * Ví dụ: Mình sẽ tiến hành pull như sau:

    ```
        git checkout master
        git pull origin master
    ```

2. `pull` từ **master** về thì ta **merge** vào branch cá nhân. Và tiếp tục làm một giấc hăng say :v
    * Lý do: update code tổng thì phải update vào code cá nhân chứ :)))

    ```
        git checkout phulh1
        git merge master
    ```

3. Khi làm được cái gì đó cảm thấy oke, đừng vội `commit` => Hãy dùng `git add .`
    * Lý do: Đưa vào **changed stage** để sau này sửa thì còn so sánh hoặc rút lui được.
	* `git add .` lần tiếp theo, thì trong **changed stage** sẽ tự động **merge** các chỉnh sửa trong các file của mình.
	    * Bấm vào sẽ thấy được thay đổi.

    ```
        git add .
    ```

4. Commit nên chia theo **chức năng** hoặc **yêu cầu** nào đó.
	* Lý do: để tránh việc `commit` khối lượng lớn lên ==> rất khó revert.
	> Cố gắng chia nhỏ nhưng phải đủ ý cho 1 commit có nghĩa.
5. À commit đừng để phần **message** vô nghĩa nha :v. Message ngắn cũng được, có thể thêm **description** vào khi tạo **PR**.
6. Commit xong thì tạo **PR (Pull Request)** trên trang github(dot)com.
	* Lưu ý xem trong mục **changed** có giống những gì mình làm hay không. Nếu có thay đổi nào mà không phải do mình làm thì báo cáo lại LEAD TEAM. ==> Create PR thui. ==> Ngủ thui
7. Tiếp theo là nhiệm vụ **merge code** của LEAD. Dò dò các thứ rồi Merge :v

> Hehe hết rùi, mọi người cứ góp ý thêm nhé <3.