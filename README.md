# 📚 Nihongo - Ứng Dụng Học Từ Vựng Tiếng Nhật

## 💡 Tại Sao Tôi Tạo Ra Ứng Dụng Này?

Khi học từ vựng từ một cuốn sách tiếng Nhật, bạn có thể gặp phải những khó khăn sau:

**Vấn đề với các ứng dụng học tập có sẵn:**
- Nhiều cuốn sách không có flashcard trên các nền tảng học tập phổ biến
- Bạn buộc phải tự tạo flashcard thủ công, mất rất nhiều thời gian
- Không thể tùy chỉnh theo nhu cầu học tập cá nhân

**Vấn đề khi học trực tiếp từ sách:**
- Phải dùng tay che tiếng Việt để ôn tiếng Nhật (hoặc ngược lại)
- Chỉ có thể ôn theo thứ tự từ đầu đến cuối, hoặc từ cuối lên đầu
- Khi che ngẫu nhiên bằng tay, dễ vô tình nhìn thấy đáp án trước khi kịp nghĩ
- Không hiệu quả và dễ nản khi phải lặp đi lặp lại

**Giải pháp của tôi:**
✅ **Nhập từ nào, học từ đó** - Tự do thêm từ vựng từ bất kỳ cuốn sách nào  
✅ **Xáo trộn ngẫu nhiên** - Mỗi lần ôn, từ vựng xuất hiện theo thứ tự khác nhau  
✅ **Không cần che tay** - Ấn phím để xem đáp án, không lo nhìn nhầm  
✅ **Lọc theo ngày** - Ôn riêng từ vựng học hôm nay, hôm qua, hoặc bất kỳ ngày nào  
✅ **Hoàn toàn miễn phí** - Không cần đăng ký, không cần internet  

---

## 🎯 Ứng Dụng Có Gì?

### 1️⃣ Hiển Thị Toàn Bộ Từ Vựng
Xem danh sách tất cả từ vựng bạn đã nhập, kèm theo tiếng Việt, tiếng Nhật và ghi chú.

### 2️⃣ Ôn Tiếng Nhật (Việt → Nhật)
- Màn hình hiển thị nghĩa tiếng Việt
- Bạn nghĩ xem từ tiếng Nhật là gì

### 3️⃣ Ôn Tiếng Việt (Nhật → Việt)
- Màn hình hiển thị từ tiếng Nhật
- Bạn nghĩ xem nghĩa tiếng Việt là gì


### 4️⃣ Thêm Từ Vựng Mới
Nhập từ mới vào ứng dụng: tiếng Việt, tiếng Nhật, và ghi chú (nếu có).

### 5️⃣ Lọc Từ Vựng Theo Ngày
- Xem danh sách các ngày bạn đã thêm từ vựng
- Chọn một ngày cụ thể
- Ôn tập chỉ với từ vựng của ngày đó

---

## 🚀 Hướng Dẫn Cài Đặt

### Có thể chỉ cần tải trực tiếp file `nihongo_app.exe` về và chạy luôn hoặc sử dụng cách dưới đây :
### Bước 1: Cài Đặt Các Công Cụ Cần Thiết

#### 📥 Cài MinGW (Trình biên dịch C++)

1. Truy cập: https://winlibs.com/
2. Tải phiên bản **UCRT runtime** mới nhất (file `.zip`)
3. Giải nén vào thư mục `C:\mingw64`
4. Thêm vào PATH:
   - Mở **Settings** → Tìm "Environment Variables"
   - Trong **System variables**, chọn **Path** → Click **Edit**
   - Click **New** → Nhập: `C:\mingw64\bin`
   - Click **OK** để lưu

5. Kiểm tra cài đặt:
   - Mở **Command Prompt** (gõ `cmd` trong Start Menu)
   - Gõ: `g++ --version`
   - Nếu hiện ra thông tin phiên bản → Thành công ✅

#### 📥 Cài CMake (Công cụ build)

1. Truy cập: https://cmake.org/download/
2. Tải file **Windows x64 Installer** (`.msi`)
3. Chạy file cài đặt
4. **Quan trọng**: Trong quá trình cài, chọn **"Add CMake to system PATH"**
5. Click **Next** → **Install**

6. Kiểm tra cài đặt:
   - Mở **Command Prompt** mới
   - Gõ: `cmake --version`
   - Nếu hiện ra thông tin phiên bản → Thành công ✅

### Bước 2: Tải Dự Án Về Máy

1. Tải file ZIP của dự án về (hoặc clone nếu biết dùng Git)
2. Giải nén vào thư mục bạn muốn, ví dụ: `C:\Users\YourName\Documents\nihongo`

### Bước 3: Chạy Ứng Dụng

#### 🎮 Cách Đơn Giản Nhất (Khuyến Nghị)

1. Mở thư mục dự án `nihongo`
2. **Double-click** vào file `build.bat`
3. Chờ chương trình tự động build và chạy
4. Xong! Ứng dụng sẽ hiện ra 🎉

#### � Cách Thủ Công (Nếu Cách Trên Không Chạy)

1. Mở **Command Prompt**
2. Di chuyển vào thư mục dự án:
   ```
   cd C:\Users\YourName\Documents\nihongo
   ```
3. Chạy lệnh build:
   ```
   .\build.bat
   ```

---


## 📁 File Dữ Liệu

Tất cả từ vựng được lưu trong file: `tuvung/flashcards.csv`

### Định Dạng File CSV

```csv
Tieng Viet,Tieng Nhat,Ghi Chu,Time
máy đánh chữ,ワープロ,をうちます＝đánh chữ,2026-02-05 12:53:15
cây nấm,キノコ,,2026-02-05 12:53:47
dép gỗ,げた,,2026-02-05 12:54:13
```
