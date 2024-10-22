/*sắp xếp chọn
    int min = 0;
    for(int i=0; i<n-1; i++){
        min = i;
        for(int j=i+1; j<n; j++){
            if(a[j] < a[i]){
                min = j;
            }
        }
        swap(a[i], a[min])
    }
*/
-----------------------------------------
/* sắp xếp chèn (tăng dần)
i là vị trí vừa là lần duyệt
    for(int i=1; i<=n-1; i++){ hoặc i < n
        x = a[i];
        int j;
        for(j=i-1; j>=0 && a[j] > x; j--){
            a[j+1] = a[j];
        }
        a[j+1] = x;
    }

*/
-----------------------------------------
/* sắp xếp nổi bọt
    i là lần duyệt, cần duyệt n-1 lần
    int flag = 0;
    for(int i=1; i<n; i++){
        flag = 0;
        for(int j=0; j<n-i; j++){ nhỏ hơn hoặc nhỏ hơn hoặc bằng đều được
            if (a[j] > a[j+1]){
                swap(a[j], a[j+1]);
                flag = 1;
            }
        }
        if(!flag) break;
    }
*/
-----------------------------------------
/*sắp xếp đổi chỗ trực tiếp
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(a[j] < a[i]){
                swap(a[j],a[i]);
            }
        }
    }
*/
-----------------------------------------
/* Shell sort (cải tiến insertion sort)
    Tại sao không dùng insertion sort đổi chổ cơ bản mà lại dùng shell sort cho phức tạp ??
    Về bản chất cũng là Simple Insertion Sort
    ✓ Ở các bước đầu, dùng Simple Insertion Sort trên các dãy con không có thứ tự nhưng đã bị chia nhỏ.
    Ở các bước sau, dùng Simple Insertion Sort trên các dãy con gần có thứ tự với kích thước lớn hơn.
    → vận dụng Simple Insertion Sort một cách rất hiệu quả
    *Số bước tiến hành không nên nhiều hay ít quá
    *ki < ki-1, bước cuối cùng có bước tăng = 1 (bước sau phải nhỏ hơn bước tăng trước)
    *Qua từng bước dãy càng có thứ tự hơn → tinh chỉnh từng bước
    
    - Yếu tố quyết định tính hiệu quả của thuật toán là cách chọn khoảng cách k; trong từng bước sắp xếp và số bước sắp xếp
    - Giả sử quyết định sắp xếp m bước, các khoảng cách chọn phải thỏa điều kiện :
    Ki > Ki+1 và Km-1 = 1
    ki (ki11)/3 và km-1 = 1, m = log3n
    Ví dụ : 127, 40, 13, 4, 1
    ki = (K1-1)/2 và km-1 = 1, m = log2n
    Ví dụ: 15, 7, 3, 1
*/
-----------------------------------------
/* Shake sort (ĐỔI CHỖ)
✓ Dựa trên nguyên tắc đổi chỗ trực tiếp, cải tiến của Bubble Sort.
✓ Ý tưởng:
-Trong mỗi lần sắp xếp, duyệt mảng theo 2 lượt từ 2 phía khác nhau:
+ Lượt đi: đẩy phần tử nhỏ về đầu mảng
+ Lượt về: đẩy phần tử lớn về cuối mảng
-Ghi nhận lại những đoạn đã sắp xếp nhằm tiết kiệm các phép so sánh thừa.
____________________________
ShakeSort(int *a, int n){
    left = 0, right = n-1;
    while(left < right){
        for(j=right; j>left; j--){
            if(a[j] vs a[j-1])
            {
                swap
                có hoán vị thì k = j;
            }lượt đi
            left = k;
        }
        for(j=left; j<right; j++){
            if(a[j] vs a[j+1])
            {
                swap
                có hoán vị thì k = j;
            }lượt về
            left = k;
        }
    }
}
* bỏ 1 vòng for là thành bubble sort =))
*/
-----------------------------------------
/* Tìm kiếm nhị phân
binarySearch(int* a, int n, int x){
    left = 0, right = n-1;
    while(left <= right){
        mid = (left+right)/2;
        if(x == a[mid]) return vị trí
        else if(x < a[mid]) right = mid - 1;
        else left = mid + 1;
    } 
}
*/
