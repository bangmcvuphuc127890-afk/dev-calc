#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <cmath>
#include <iomanip>
#include <print> 
#include <numbers>
#include <expected>
#include <cstddef>
#include <complex>
#include <functional>
#include <sstream>
#include <cstdio> // :D
#include <array>
#include <chrono>
#include <thread>
#include <fstream>
#include <filesystem>
#include <algorithm>
#include <cstdlib>
//c++23?!

//Nhan dien: #ifdef:
#ifdef _WIN32
    #include <windows.h>
    #define operator_system "Windows - Operator System"
#elif __linux__
    #include <unistd.h>
    #define operator_system "Linux - Operator System"
#elif __ANDROID__
    #define operator_system "Android - OS"
#endif

//Map:
#include <map>
std::map<std::string, double> luu_gia_tri;

//using:
using namespace std;

//namespace
namespace BangGaming8826
{
    // ANSI Colorful: 
    const constexpr string_view mau_do = "\033[31m";
    const constexpr string_view vang = "\033[33m";
    const constexpr string_view xanh_la = "\033[32m";
    const constexpr string_view purple = "\033[35m";
    const constexpr string_view nghiem = "\033[3m";
    const constexpr string_view res = "\033[0m";   
    const constexpr string_view clr = "\033[2J\033[1;1H";
    constexpr string_view phien_ban = "jugar 0.2.1 alpha";
    auto dev_info = [] (bool xem_thong_tin = false)
    {
        if (xem_thong_tin == true)
        {
            std::println("Creator Namme:{} BangGaming8826{}", nghiem, res);
            std::println("Age of creator: No say (2015)");
            std::println("======================================");
            std::println("Product Name: Máy tính C++ nho nhỏ");
            std::println("Product Version: {}", phien_ban);
            std::println("{} jugar = beta, pjug = preview {}",nghiem, res);
            std::println("My Operator System (OS): {}", operator_system);
            std::println("Language: VIỆT NAM and ENGLISH");
        }
    };
};
namespace GiaoDien
{
    /* Windows: */ #ifdef _WIN32
    auto windows_window = [] (int opacity, int x, int y, int wei, int hei) -> void
    {
       static HWND home_calc_frame = GetConsoleWindow();  
       SetConsoleTitle("Devoloper Calculator - BangGaming8826");
       MoveWindow(home_calc_frame, x, y, wei, hei, true);
       SetWindowLong(home_calc_frame, GWL_EXSTYLE, GetWindowLong(home_calc_frame, GWL_EXSTYLE) | WS_EX_LAYERED);
       SetLayeredWindowAttributes(home_calc_frame, 0, opacity, LWA_ALPHA);
    };   
    /* Linux: */ #elif __linux__
    auto delay_text = [] (int delay, string text_font) -> void
    {
        for (char text_print : text_font)
        {
            cout << text_print << std::flush;
            usleep(delay);
        }
        cout << endl;
    };
    auto usar_press = []() -> void
    {
        if (getuid() == 0) std::println("[i] {}Root User{} [<∑>]", BangGaming8826::mau_do, BangGaming8826::res);
        else std::println("[i] {}Normal User{} [<◕→◕>]",BangGaming8826::xanh_la, BangGaming8826::res);
    };
    #endif
};

//function / class:
class tao_ma_tran
{
private:
public:
    size_t hang,cot; 
    vector<long double> bang_matran; 
    tao_ma_tran(): hang(), cot(), bang_matran(){};
    tao_ma_tran(size_t hang, size_t cot): hang(hang), cot(cot), bang_matran((hang > 0 && cot > 0) ? hang * cot : 1)
    {
        std::println("Đã tạo ma trận!");
    };
    void set_giatri(size_t hang, size_t cot) {bang_matran.assign((hang > 0 && cot > 0) ? hang*cot : 1, 0);}
};

//template

complex<long double> comp1, comp2, so_ao;
complex<int> i_i;
complex<long double> i_d;
long double rad, thet;

 //symbol của toán học ?!
    const constexpr long double sym_pi = std::numbers::pi_v<long double>;
    const constexpr long double sym_euler = std::numbers::e_v<long double>;
    const constexpr long double sym_tile_vang = std::numbers::phi_v<long double>;
    const constexpr long double sym_tau = 2 * sym_pi;
    const constexpr long double sym_egamma = std::numbers::egamma_v<long double>;
    const constexpr long double sym_sqrt2_pytago = std::numbers::sqrt2_v<long double>, sym_sqrt3_pytago = std::numbers::sqrt3;
    const constexpr long double sym_sqrt5_pytago = sqrt(5.0L);
    //const constexpr long double sym_log2 = std::numbers::log2_v<long double>, sym_log10 = std::numbers::log10_v<long double>;
    const constexpr long double sym_log2e = std::numbers::log2e_v<long double>, sym_log10e = std::numbers::log10e_v<long double>;
//struct
struct Toanhoc
{
    long double sothu1, sothu2,input, ket_qua, st1, st2;
    long long s;
    string type_pheptinh, is_clear_running;
    bool is_clear;
    string catche, inputs;
    size_t input1, input2;
    
}; 

//expected
std::expected<long double, string> chia_loi(Toanhoc &toanvn)
{
    if (toanvn.sothu2 == 0)
    {
        return std::unexpected("Error -1: Division by zero! ");
    }
    return toanvn.sothu1 / toanvn.sothu2;
} 
std::expected<bool, string> loi_file(string cu, string moi)
{
    if (std::filesystem::exists(cu))
    {
        std::filesystem::rename(cu, moi);
        std::println("Rename file: {} -> {} completed!", cu, moi);
        return true;
    }
    else return std::unexpected("ERROR: Input_Stream_ERROR(in dir: ./res::input_stream_dir_div/)");
}
void toanviet(Toanhoc toanvn); // Khỏi bị infinite mèo đuổi chuột nữa...
void mode(Toanhoc toanvn); // Khỏi bị infinite chuột đuổi mào nữa...

Toanhoc toanvn;
//lambda and function:
    static auto mclear_screen = []() -> string
    {
         string a;
         std::println("Enter 'clear!' to clear screen");
         cin >> a;
         if (a == "clear!")
         {
             #ifdef _WIN32
                system("cls");
                mode(toanvn);
             #else
                system("clear");
                mode(toanvn);
             #endif
         }
         return "Ok";
     };
    static auto clear_screen = []() -> string
    {
        string a;
         std::println("Enter 'clear!' to clear screen");
         cin >> a;
         
         if (a == "clear!")
         {
             #ifdef _WIN32
                system("cls");
                toanviet(toanvn);
             #else
                system("clear");
                toanviet(toanvn);
             #endif   
         }
         return "Ok";
     }; 
    static auto lang_vietnam = []() -> void
    {
    std::println("{:>35}","Máy tính C++ -----------{}{}{}", BangGaming8826::xanh_la," BangGaming8826 ", BangGaming8826::res);
    std::println("{:>35}","===========================================");
    std::println("Gõ các kí tự trong " , "{}{}{}{}" ,BangGaming8826::mau_do,"[]",BangGaming8826::res," để mở tính toán:");
    std::println("[+] Cộng");
    std::println("[-] Trừ");
    std::println("[x] Nhân");
    std::println("[÷] Chia");
    std::println("[^] Tính mũ (x^y)");
    std::println("[10^y] Tính 10 mũ (10^y)");
    std::println("[x!] Tính giai thừa (n!)");
    std::println("[sin] Tính sin");
    std::println("[cos] Tính cos");
    std::println("[tan] Tính tan");
    std::println("[hyp] Tính về các operator như sinh,...");
    std::println("[log] Tính log_10(x)");
    std::println("[log_x] Tính log_x(y)");
    std::println("[ln] Tính log_e(x)");
    std::println("[||] Tính các hàm số (giá trị tuyệt đối, trần, sàn)");
    std::println("[sqrt] Tính căn bậc 2 hay x");
    std::println("");
    std::println("[import-answer] Lưu kết quả...");
    std::println("[export-answer] Xuất kết quả...");
    std::println("[list-answer] Liệt kê danh sách kết quả...");
    std::println("[delete-answer] Xóa kết quả...");
    std::println("[mode] Chuyển chế độ...");
    std::println("[lang] Chuyển ngôn ngữ // Swich Language (Loi thoi)");
    
    std::print("{:>2}","Nhập: ");
    }; //Viet Nam!!!

long double chu_so_string(string tb = "", bool ndefault = false)
{
	if (tb == "pi" || tb == "π") return sym_pi;
	else if (tb == "e" || tb == "euler") return sym_euler;
	else if (tb == "gold_ratio" || tb == "ϕ") return sym_tile_vang;
	else if (tb == "egamma" || tb == "γ") return sym_egamma;
	else if (tb == "tau" || tb == "τ" || tb == "2*pi") return sym_tau;
	else if (tb == "sqrt2") return sym_sqrt2_pytago;
	else if (tb == "sqrt3") return sym_sqrt3_pytago;
	else if (tb == "sqrt5") return sym_sqrt5_pytago;
	else if (tb == "log2e") return sym_log2e;
	else if (tb == "log10e") return sym_log10e;
	else if (ndefault == true) return sym_pi;
	else 
	{
		try {
			return std::stold(tb);
		}
		catch (...) {
			std::println("ERROR: ConstantIvailid()");
			std::println("Info: ResetReturn(in dir: ./res::info_return_reset_with_num; id: 0)");
			std::println("Info: Reset the return: 0; InfoId: ResetReturn(0)");
			return 0.0L;
		}

	}
}
void hardware_operator(int zoner)
{
#ifdef __linux__
	char info[1000];
	string cpu_pth = "/sys/class/thermal/thermal_zone" + std::to_string(zoner) + "/temp";
	std::println("===={} Infomation: ====", operator_system);

	FILE *ram = fopen("/proc/meminfo", "r");
	std::println("- {}[1]{} RAM (Memory Usage):", BangGaming8826::xanh_la, BangGaming8826::res);
		
		for (int i = 0; i < 3; i++) 
		{
			if (fgets(info, sizeof(info), ram))
			{
				std::print("- {}", info);
			}
		}
		fclose(ram);
	FILE *cpu = fopen("/proc/stat", "r");
		std::println("- {}[2]{} CPU (Processor): ", BangGaming8826::vang, BangGaming8826::res);
		std::println("Core————User————Nice————System————Sleep-(Idle):      —[ranger&■]—");
		while(fgets(info, sizeof(info), cpu)) {std::print("- {}", info);}
		fclose(cpu);
	FILE *c_cpu = fopen(cpu_pth.c_str(), "r");
		if (fgets(info, sizeof(info), c_cpu)) std::print("- mili°C: {}", info);
		fclose(c_cpu);
		std::println("- {}[3]{} APPS (Programmer)", BangGaming8826::vang, BangGaming8826::res);
		std::println("Apps has running in system——————————");
		for (const auto &trom_app : std::filesystem::directory_iterator("/proc"))
		{
			string trom_app_chay = trom_app.path().filename().string();
			if (trom_app.is_directory() && std::isdigit(trom_app_chay[0]))
			{
				std::ifstream cam_nhin_fileten("/proc/" + trom_app_chay + "/comm");
				string cccd_app;

				if (getline(cam_nhin_fileten, cccd_app))
				{
					std::println("-> [{}] {}", trom_app_chay, cccd_app);
				}
			}
		}
		std::println("- {}[4]{} BATTERY (Power of device):", BangGaming8826::vang, BangGaming8826::res);
	FILE *pt_pin = fopen("/sys/class/power_supply/battery/capacity", "r");
		if (pt_pin != nullptr)
		{
			fgets(info, sizeof(info), pt_pin);
			std::print("- Battery Percentage (%): {}", info);
			fclose(pt_pin);
		}
	FILE *tth_pin = fopen("/sys/class/power_supply/battery/status", "r");
		if (tth_pin != nullptr)
		{
			fgets(info, sizeof(info), tth_pin);
			std::print("- Battery Status: {}", info);
			fclose(tth_pin);
		}
	FILE *suckho_epin = fopen("/sys/class/power_supply/battery/health", "r");
		if (suckho_epin != nullptr) 
		{
			fgets(info, sizeof(info), suckho_epin);
			std::print("- Battery Health: {}", info);
			fclose(suckho_epin);
		}
	FILE *do_pin = fopen("/sys/class/power_supply/battery/temp", "r");
		if (do_pin != nullptr) 
		{
			fgets(info, sizeof(info), do_pin);
			std::print("- Battery Temp: {}", info);
			fclose(do_pin);
		}
#else
		std::println("The {} is not support command!", operator_system);
#endif
}

void mode(Toanhoc toanvn)
{
    //endl lambda 
    std::println("============== CHẾ ĐỘ CACLULATOR / Calculator Mode =============");
    std::println("[1] Tính bình thường - Calculator with Normal (Vietnamese)");
    std::println("[2] Số ảo - Calculator with Complex (Vietnamese)");
    std::println("[3] Hệ số - Calculator with Base-Number (Vietnamese)");
    std::println("[4] Ma trận - Calculator with Matrix [Beta] (Vietnamese)");
    std::println("[5] Lệnh - SHELL (English) (For Devoloper)");
    std::println("[6] Vectơ - Vector [Preview] (Vietnamese)");
    std::println("[7] Bảng (hàm f(x), g(x) - Calc with Function (Table) (Vietnamese)\n");
    std::println("[-1] Thoát - QExit");
    std::print("Nhập đầu vào - ENTER INPUT: ");
    cin >> toanvn.type_pheptinh;
    
    if (toanvn.type_pheptinh == "-1")
    {
	    char a;
	    std::print("Are sure to exit? (t/f): ");
	    cin >> a;
	if (a == 't' || a == 'y') std::quick_exit(0);
    }
	else if (toanvn.type_pheptinh == "1")
    {
        string theclear = clear_screen();
        (void)theclear;
    } // thường
    
   else  if (toanvn.type_pheptinh == "2")
    {
        string local_type;
       std::println("{:^55}","=============WELCOME TO COMPLEX (i) ============== ");
       std::println("[+] cộng");
       std::println("[-] trừ");
       std::println("[x] nhân");
       std::println("[:] chia");
       std::println("[^] mũ");
       std::println("[sqrt] căn");
       std::println("[conj] liên hợp");
       std::println("[lgi] lượng giác");
       std::println("[p/_] tọa độ cực");
       std::println("[r/_] tọa độ đề các\n");
       string lc;
       std::print("nhập đầu vào: ");
       cin >> lc;
       
       if (lc == "+")
       {
            
           std::println("Enter num 1 (a+bi): "); cin >> toanvn.sothu1 >> toanvn.sothu2;
           std::println("Enter num 2 (x+yi): "); cin >> toanvn.st1 >> toanvn.st2;
           comp2 = {toanvn.st1, toanvn.st2};
           comp1 = {toanvn.sothu1, toanvn.sothu2}; 
           auto i_ket_qua = comp1 + comp2;
           std::println("Result is: {} + {}i", i_ket_qua.real(), i_ket_qua.imag());
           string theclear = mclear_screen ();
           (void)theclear;
       }
       if (lc == "-")
       {
           std::println("Enter num 1 (a+bi):"); cin >> toanvn.st1 >> toanvn.st2;
           std::println("Enter num 2 (c+di):"); cin >> toanvn.sothu1 >> toanvn.sothu2;
           comp1= {toanvn.st1, toanvn.st2};
           comp2= {toanvn.sothu1, toanvn.sothu2}; 
           auto i_ket_qua = comp1 - comp2;
           std::println("Result is: {} + {}i", i_ket_qua.real(), i_ket_qua.imag());
           string theclear = mclear_screen();
           (void)theclear;
       }
       if (lc == "x")
       {
           std::println("Nhập số thứ 1 (a×bi):"); cin >> toanvn.st1 >> toanvn.st2;
           std::println("Nhập số thứ 2 (c×di):"); cin >> toanvn.sothu1 >> toanvn.sothu2;
           comp1={toanvn.st1, toanvn.st2};
           comp2={toanvn.sothu1, toanvn.sothu2}; 
           auto i_ket_qua = comp1 * comp2;
           std::println("Kết quả là: {} + {}i", i_ket_qua.real(), i_ket_qua.imag());
           string theclear = mclear_screen();
           (void)theclear;
       }
       if (lc == ":")
       {
           std::println("Nhập số thứ 1 (a÷bi):"); cin >> toanvn.st1 >> toanvn.st2;
           std::println("Nhập số thứ 2 (c÷di):"); cin >> toanvn.sothu1 >> toanvn.sothu2;
           comp1={toanvn.st1, toanvn.st2};
           comp2={toanvn.sothu1, toanvn.sothu2}; 
           auto i_ket_qua = comp1 / comp2;
           std::println("Kết quả là: {} + {}i", i_ket_qua.real(), i_ket_qua.imag());
           string theclear = mclear_screen();
           (void)theclear;
       }
       if (lc == "^")
       {
              string lcc;
          std::print("Nhập kiểu tính ([^^] Số mũ thường, [i^] Tính i mũ, [^i] Tính mũ i, [a+bi^] Tính số phức liên hợp mũ, [^a+bi] Tính mũ số phức liên hợp: ");
          cin >> lcc;
          
          // ^^ MŨ THƯỜNG: 
          if (lcc == "^^")
          {
            std::print("Nhập cơ số: "); cin >> toanvn.sothu1;
            std::print("Nhập mũ số: "); cin >> toanvn.sothu2;
            toanvn.ket_qua = pow(toanvn.sothu1, toanvn.sothu2);
            std::println("Kết qủa của {}^{} là: {}", toanvn.sothu1, toanvn.sothu2, toanvn.ket_qua);
            string theclear = mclear_screen();
            (void)theclear;
          }
          if (lcc == "i^")
          {
             std::print("Nhập mũ số: "); cin >> toanvn.sothu2;
             i_i={0, 1};
             so_ao = pow(i_i, toanvn.sothu2);
             std::println("Kết qủa của i^{} là: {} + {}i", toanvn.sothu2, so_ao.real(), so_ao.imag());
             string theclear = mclear_screen();
             (void)theclear;
          }
          if (lcc == "^i")
          {
              i_i={0, 1}; 
              std::print("Nhập cơ số: "); cin >> toanvn.sothu2;
              so_ao = pow(toanvn.sothu2, i_i);
              std::println("Kết quả của {}^i là: {} + {}i", toanvn.sothu2, so_ao.real(), so_ao.imag());
              string theclear = mclear_screen();
              (void)theclear;
          }
          
          if (lcc == "a+bi^")
          {
              std::print("Nhập phần thực: "); cin >> toanvn.sothu1;
              std::print("Nhập phần ảo: "); cin >> toanvn.sothu2;
              std::print("Nhập mũ số: "); cin >> toanvn.input;
              comp1 = {toanvn.sothu1, toanvn.sothu2};
              so_ao = pow(comp1, toanvn.input);
              std::println("Kết quả là: {} + {}i",so_ao.real(), so_ao.imag());
              string theclear = mclear_screen();
              (void)theclear;
          }
          
          if (lcc == "^a+bi")
          {
              std::print("Nhập phần thực: "); cin >> toanvn.sothu1;
              std::print("Nhập phần ảo: "); cin >> toanvn.sothu2;
              std::print("Nhập cơ số: "); cin >> toanvn.input;
              comp1 = {toanvn.sothu1, toanvn.sothu2};
              so_ao = pow(toanvn.input, comp1);
              std::println("Kết quả là: {} + {}i", so_ao.real(), so_ao.imag());
              string theclear = mclear_screen();
              (void)theclear;
          }
       } // mũ
       if (lc == "sqrt")
       {
           string lcb;
           std::print("Nhập kiểu tính ([sq2] Tính căn bậc 2, [n] Tính căn bậc n, [cq3] Tính căn bậc 3, [sqi] Tính bậc n của i, [isq] Tính căn bậc i, [sqa+bi] Tính căn bậc n của a+bi): "); cin >> lcb;
           
           // CĂN - SQRT:
           if (lcb == "sq2")
       {
           std::print("Nhập đầu vào: ");
           cin >> toanvn.sothu2;
           toanvn.ket_qua = sqrt(toanvn.sothu2);
           std::println("Kết quả của căn bậc 2 của {} là: {}", toanvn.sothu2 , toanvn.ket_qua);
          string theclear = mclear_screen();
          (void)theclear;
       }//end bậc 2!
       
       if (lcb == "n")
       {
           std::print("Nhập bậc của căn: ");
           cin >> toanvn.sothu1;
           std::print("Nhập đầu vào: ");
           cin >> toanvn.sothu2;
           toanvn.ket_qua = pow(toanvn.sothu2, 1.0 / toanvn.sothu1);
           std::println("Kết của của căn bậc {} của {} là: {}", toanvn.sothu1, toanvn.sothu2, toanvn.ket_qua);
       string theclear = mclear_screen();
       (void)theclear;
   } // end of sqrt(n)
   
   if (lcb == "cq3")
   {
       std::print("Nhập đầu vào: ");
       cin >> toanvn.sothu2;
       toanvn.ket_qua = cbrt(toanvn.sothu2);
       std::println("Kết của của căn bậc 3 của {} là: {}", toanvn.sothu2, toanvn.ket_qua);
        string theclear = mclear_screen();
        (void)theclear;
   } // sqrt 3
  
  if (lcb == "sqi")
  {
      std::print("Nhập căn bậc: "); cin >> toanvn.sothu2;
      i_i={0, 1}; 
      so_ao = pow(i_i, 1.0 / toanvn.sothu2);
      std::println("Kết quả của căn bậc {} của i là: {} + {}i", toanvn.sothu2, so_ao.real(), so_ao.imag());
      string theclear = mclear_screen();
      (void)theclear;
      
  }
  if (lcb == "isq")
  {
      std::print("Nhập đầu vào: "); cin >> toanvn.sothu2;
      i_d={0.0, 1.0};
      complex<long double> so_ao = pow(toanvn.sothu2, complex<long double>(1.0, 0.0) / i_d);
      std::println("Kết quả của căn bậc i của {} là: {} + {}i", toanvn.sothu2, so_ao.real(), so_ao.imag());
      string theclear = mclear_screen();
      (void)theclear;
  }
  // KHÔNG ĐUỌEC CHỈNH SƯAR
  if (lcb == "sqa+bi")
  {
      std::print("Nhập phần thực (a): ");
      cin >> toanvn.sothu1;
      std::print("Nhập phần ảo (b): ");
      cin >> toanvn.sothu2;
      std::print("Nhập bậc (n)");
      cin >> toanvn.input;
      std::print("Nhập phần ảo của bậc (ni) (nhập 0 nếu ko muốn): ");
      long double inpuut;
      cin >> inpuut;
      comp1 = {toanvn.sothu1, toanvn.sothu2};
      comp2 = {toanvn.input, inpuut};
      auto ket_qua = pow(comp1, complex<long double>(1.0, 0.0) / comp2);
      if (comp2.imag() > 0)
      {
          std::println("Kết quả của căn bậc {} của {} + {} là: {} + {}i", comp2.real(), comp1.real(), comp1.imag(), ket_qua.real(),ket_qua.imag());
          string theclear = mclear_screen();
          (void)theclear;
      }
      else 
      {
          std::println("Kết quả của căn bậc {} + {} của {} + {} là: {} + {}i", comp2.real(), comp2.imag(), comp1.real(), comp1.imag(), ket_qua.real(), ket_qua.imag());
          string theclear = mclear_screen();
          (void)theclear;
      }
  }
      if (lcb == "a+bi-sq")
  {
      std::print("Nhập bậc - phần thực (a): ");
      cin >> toanvn.sothu1;
      std::print("Nhập bậc - phần ảo (b): ");
      cin >> toanvn.sothu2;
      std::print("Nhập đầu vào (n)");
      cin >> toanvn.input;
      std::print("Nhập phần ảo của đuầu vào (ni) (nếu không thì để 0)");
      long double inpuut;
      cin >> inpuut;
      comp1 = {toanvn.sothu1, toanvn.sothu2};
      comp2 = {toanvn.input, inpuut};
      auto ket_qua = pow(comp2, complex<long double>(1.0, 0.0) / comp1);
      if (comp2.imag() == 0)
      {
          std::println("Kết quả của căn bậc {} + {}i của {} là: {} + {}i", comp1.real(), comp1.imag(), toanvn.input, ket_qua.real(),ket_qua.imag());
          string theclear = mclear_screen();
          (void)theclear;
      }
      else 
      {
          std::println("Kết quả của căn bậc {} + {}i của {} + {}i là: {} + {}i", comp1.real(), comp1.imag(), comp2.real(), comp2.imag(), ket_qua.real(),ket_qua.imag());
          string theclear = mclear_screen();
          (void)theclear;
      }
      }
  
       } // sqrt:))) 
    if (lc == "lgi")
    {
        std::print("Nhập kiểu tính ([sin], [cos], [tan], [hyp], [ihyp] : ");
        cin >> toanvn.inputs;
        if (toanvn.inputs == "sin")
    {
        string typesin;
        cout << "Chọn kiểu tính sin ([d] độ, [r] radian): ";
        cin >> typesin;

        if (typesin == "r")
        {
            cout << "Nhập đầu vào: ";
            cin >> toanvn.sothu1;
            toanvn.ket_qua = sin(toanvn.sothu1);
            cout << "Kết quả của sin("<< toanvn.sothu1 << ") là: " << toanvn.ket_qua << endl;
            string theclear = mclear_screen();
            (void)theclear;
        }

        if (typesin == "d")
        {
            cout << "Nhập đầu vào: ";
            cin >> toanvn.sothu2;
            toanvn.sothu1 = toanvn.sothu2 * (sym_pi / 180);
            toanvn.ket_qua = sin(toanvn.sothu1);
            cout << "Kết quả của sin(" << toanvn.sothu2 << "°) là: " << toanvn.ket_qua << endl;
            string theclear = mclear_screen();
            (void)theclear;
        }
    } //el sin

    if ( toanvn.inputs== "cos")
    {
        string typecos;
        cout << "Chọn kiểu tính cos ([d] độ, [r] radian): ";
        cin >> typecos;

        if (typecos == "r")
        {
            cout << "Nhập đầu vào: ";
            cin >> toanvn.sothu1;
            toanvn.ket_qua = cos(toanvn.sothu1);
            cout << "Kết quả của cos(" << toanvn.sothu1 << ") là: " << toanvn.ket_qua << endl;
            string theclear = mclear_screen();
            (void)theclear;
        }

        if (typecos == "d")
        {
            cout << "Nhập đầu vào: ";
            cin >> toanvn.sothu2;
            toanvn.sothu1 = toanvn.sothu2 * (sym_pi / 180);
            toanvn.ket_qua = cos(toanvn.sothu1);
            cout << "Kết quả của cos(" << toanvn.sothu2 << " độ) là: " << fixed << toanvn.ket_qua << endl;
            string theclear = mclear_screen();           
            (void)theclear;
        }

    } // el cos

    if (toanvn.inputs == "tan")
    {
        string typetan;
        cout << "Nhập kiểu tính tan ([d] độ, [r] radian): ";
        cin >> typetan;

        if (typetan == "d")
        {
            cout << "Nhập đầu vào (lớn hơn 90° thì tan tiến tới vô cùng): ";
            cin >> toanvn.sothu2;
            toanvn.sothu1 = toanvn.sothu2 * (sym_pi / 180);
            toanvn.ket_qua = tan(toanvn.sothu1);
            cout << "Kết quả của tan(" << toanvn.sothu2 <<" độ) là: " <<toanvn.ket_qua << endl;
            string theclear = mclear_screen();
            (void)theclear;
        } 


        if (typetan == "r")
        {
            cout << "Nhập đầu vào: ";
            cin >> toanvn.sothu1;
            toanvn.ket_qua = tan(toanvn.sothu1);
            cout << "Kết quả của tan(" << toanvn.sothu1 << ") là: " << fixed <<toanvn.ket_qua << endl;
            string theclear = mclear_screen();
            (void)theclear;
        }
    } //el tan
    
    if (toanvn.inputs == "hyp")
    {
        string stdf;
       std::print("Nhập kiểu cho hyp (sinh, cosh, tanh): ");
       cin >> stdf;
       
       if (stdf == "sinh")
       {
           std::print("Nhập đầu vào: ");
           cin >> toanvn.sothu2;
           toanvn.ket_qua = sinh(toanvn.sothu2);
           std::println("Kết quả của sinh({}) là: {} ", toanvn.sothu2, toanvn.ket_qua);
           string theclear = mclear_screen();
           (void)theclear;
       
    }
    
    if (stdf == "cosh")
    {
        std::print("Nhập đầu vào: ");
        cin >> toanvn.sothu2;
        toanvn.ket_qua = cosh(toanvn.sothu2);
        std::println("Kết quả của cosh({}) là: {}", toanvn.sothu2, toanvn.ket_qua);
        string theclear = mclear_screen();
        (void)theclear;
    }
    
    if (stdf == "tanh")
    {
        std::print("Nhập đầu vào: ");
        cin >> toanvn.sothu2;
        toanvn.ket_qua = tanh(toanvn.sothu2);
        std::println("Kết quả của tanh({}) là: {}", toanvn.sothu2, toanvn.ket_qua);
        string theclear = mclear_screen();
        (void)theclear;
    }
} // HYP

    if (toanvn.inputs == "ihyp") 
    {
        string ihuyp;
       std::print("Nhập kiểu ([asin] Tính arcsin, [acos] tính arcos, [atan] tính tan | [asinh] tính arcsinh ,[acosh] tính arccosh, [atanh] tính arctanh"); 
       cin >> ihuyp;
        if (ihuyp == "asin")
        {
        std::print("Enter your number 1: "); cin >> toanvn.sothu1;
        std::print("Nhập số thứ 2 (i): "); cin >> toanvn.sothu2;
        comp1={toanvn.sothu1, toanvn.sothu2};
        so_ao = asin(comp1);
        std::println("Kết quả là: {} + {}i", so_ao.real(), so_ao.imag());
        string theclear = mclear_screen();
        (void)theclear;
        } //asin
        
        if (ihuyp == "acos")
        {
        std::print("Enter your number 1: "); cin >> toanvn.sothu1;
        std::print("Nhập số thứ 2 (i): "); cin >> toanvn.sothu2;
        comp1={toanvn.sothu1, toanvn.sothu2};
        so_ao = acos(comp1);
        std::println("Kết quả là: {} + {}i", so_ao.real(), so_ao.imag());
        string theclear = mclear_screen();
        (void)theclear;
        } //acos
        
        if (ihuyp == "atan")
        {
        std::print("Enter your number 1: "); cin >> toanvn.sothu1;
        std::print("Nhập số thứ 2 (i): "); cin >> toanvn.sothu2;
        comp1={toanvn.sothu1, toanvn.sothu2};
        so_ao = atan(comp1);
        std::println("Kết quả là: {} + {}i", so_ao.real(), so_ao.imag());
        string theclear = mclear_screen();
        (void)theclear;
        } //atan
        
        if (ihuyp == "asinh")
        {
        std::print("Enter your number 1: "); cin >> toanvn.sothu1;
        std::print("Nhập số thứ 2 (i): "); cin >> toanvn.sothu2;
        comp1={toanvn.sothu1, toanvn.sothu2};
        so_ao = asinh(comp1);
        std::println("Kết quả là: {} + {}i", so_ao.real(), so_ao.imag());
        string theclear = mclear_screen();
        (void)theclear;
        } //asinh
        
        if (ihuyp == "acosh")
        {
        std::print("Enter your number 1: "); cin >> toanvn.sothu1;
        std::print("Nhập số thứ 2 (i): "); cin >> toanvn.sothu2;
        comp1={toanvn.sothu1, toanvn.sothu2};
        so_ao = acosh(comp1);
        std::println("Kết quả là: {} + {}i", so_ao.real(), so_ao.imag());
        string theclear = mclear_screen();
        (void)theclear;
        } //acosh
        
        if (ihuyp == "atanh")
        {
        std::print("Enter your number 1: "); cin >> toanvn.sothu1;
        std::print("Nhập số thứ 2 (i): "); cin >> toanvn.sothu2;
        comp1={toanvn.sothu1, toanvn.sothu2};
        so_ao = atanh(comp1);
        std::println("Kết quả là: {} + {}i", so_ao.real(), so_ao.imag());
        string theclear = mclear_screen();
        (void)theclear;
        } //atanh
    } // iHYP
    
    } // LƯỢNG GIÁC PHỨC
    
    if (lc == "p/_")
    {
        std::print("Nhập phần thực: "); cin >> toanvn.sothu1;
        std::print("Nhập phần ảo: "); cin >> toanvn.sothu2;
        comp1 = {toanvn.sothu1, toanvn.sothu2};
        rad = abs(comp1);
        thet = arg(comp1); // ¡TÍNH THETA (ghi nhớ!!)!
        toanvn.ket_qua = thet *180 / sym_pi;
        std::println("Kết quả là: r = {} , theta = {} , độ = {} ", rad, thet, toanvn.ket_qua);
        string theclear = mclear_screen();
        (void)theclear;
    } // CỰC POLAR BEAR :)
    
    if (lc == "r/_")
    {
       std::print("Nhập bán kính: "); cin >> toanvn.sothu1;  
       std::print("Nhập độ: "); cin >> toanvn.sothu2;
       rad = toanvn.sothu2 * sym_pi / 180 ;
       long double x_pos = toanvn.sothu1 * cos(rad);
       long double y_pos = toanvn.sothu1 * sin(rad);
       comp1 = {x_pos, y_pos};
       std::println("Kết quả là: x = {}, y = {}, độ = {}", x_pos, y_pos, rad);
       std::println("          : {} + {}i", comp1.real(), comp1.imag());
       string theclear = mclear_screen();
       (void)theclear;
    } // đề các
    
    if (lc == "conj")
    {
        std::print("Nhập phần thực: "); cin >> toanvn.sothu1;
        std::print("Nhập phần ảo: "); cin >> toanvn.sothu2;
        comp1 = {toanvn.sothu1, toanvn.sothu2};
        so_ao = conj(comp1);
        std::println("Kết quả là: {} + {}i", so_ao.real(), so_ao.imag());
        string theclear = mclear_screen();
        (void)theclear;
    }

    
    } //ảo ma i
    
   else if (toanvn.type_pheptinh == "3")
    {
       string mdee;
       long long inputt;
       std::print("Nhập số: "); cin >>inputt;
       std::print("Nhập kiểu bạn muốn chuyển ([hex] Hệ Thập Lục phân, [oct] Hệ bát phân , [bin] Hệ nhị phân, [dec] Hệ thập phân):  ");
       cin >> mdee;
       
       if (mdee == "hex")
       {
           std::println("Kết quả là: {:x} hay {:X}", inputt, inputt);
           string theclear = mclear_screen();
           (void)theclear;
       } 
       if (mdee == "oct")
       {
           std::println("Kết quả là: {:o}", inputt);
           string theclear = mclear_screen();
           (void)theclear;
       }
       if (mdee == "bin")
       {
           std::print("Kết quả là: {:b}", inputt);
           string theclear = mclear_screen();
           (void)theclear;
       }
       if (mdee == "dec")
       {
           std::print("Kết quả là: {:d}", inputt);
           string theclear = mclear_screen();
           (void)theclear;
       }
    } // hệ số
    
   else if (toanvn.type_pheptinh == "4")
    {
        //Ma tran:D
     static long double matran_2x3[6], matran_2x2[4];
     static int matran_chuyenvi[4] = {1,0,1,0}; 
     static std::array<tao_ma_tran, 6> matran_cuaban;
     std::print("{:^55}","===============WELCOME TO MATRIX================");
     std::println("[++] Thay đổi/Tạo ma trận");
     std::println("[+] Cộng ma trận");
     std::println("[-] Trừ ma trận");
     std::println("[x] Nhân ma trận");
     std::println("[:] Chia ma trận");
     
     cin >> toanvn.type_pheptinh;
     
     if (toanvn.type_pheptinh == "++")
     {
        int mt;
        std::println("Tối đa số ma trận là: 5");
        std::println("[0] Ma trận 0");
        std::println("[1] Ma trận 1");
        std::println("[2] Ma trận 2");
        std::println("[3] Ma trận 3");  
        std::println("[4] Ma trận 4");
        std::println("[5] Ma trận 5");
        std::println("=================");
        std::println("[-1] Thay đổi GT ma ma trận");
        std::print("{:^2}","Nhập (0 -> 5) ma trận: ");
        cin >> mt;
        std::print("Nhập hàng: ");
        cin >> toanvn.input1;
        std::print("Nhập cột: ");
        cin >> toanvn.input2;
        
        if (mt >= 0 && mt <= 5)
        {
            matran_cuaban.at(mt).set_giatri(toanvn.input1, toanvn.input2);
            std::println("Đã tạo ma trận! :D");
            string theclear = mclear_screen();
            (void)theclear;
        }
        else if (mt == -1)
        {
            long long mtt, vitri;
            std::print("Nhập số ma trận: ");
            cin >> mtt;
            std::print("Nhập vị trí (ma trận với size: {}x{}): ", matran_cuaban.at(mtt).hang, matran_cuaban.at(mtt).cot);
            cin >> vitri;
            if (vitri >= 0 && vitri < (matran_cuaban.at(mtt).hang * matran_cuaban.at(mtt).cot))
            {
                long long vt = (mtt *matran_cuaban.at(mtt).hang * matran_cuaban.at(mtt).cot) + vitri;
                std::println("Vị trí phần tử cũ có số là: {}", vt);
                std::println("Nhập số tại vị trí {}: ", vt);
                cin >> toanvn.sothu1;
                matran_cuaban.at(mtt).bang_matran.at(vitri)= toanvn.sothu1;
                std::println("[✓] Đã thay đổi phần tử {} ma trận {}!",vitri ,mtt);
                string theclear = mclear_screen();
                (void)theclear;
            }
            
        }
        else
        {
            std::println("/project/BangGaming8826/calculator/system-caragor/bin/28365357253588565832552583773225/modune-cpp-files/modes/matrix/warning-carango-of-matrix-options/warning-carango-of-matrix-options.json:: ERROR -1: Không tìm thấy Ma trận {} với đường dẫn: !", mt);
            std::println("/                                                    /5288536577522557256767365665856885658656868565885628383558/modune-cpp-files/modes/matrix/matrix-local-bin/53178856045586518586518685518565106001556005106587874578468784883845484646188756156588585885156885153885358151738517351585831583581585831535883558185381583588158351583588153588658848645785678305645581507376175817350172175323187157301765871207065178165781578175852025025002549673488050658008405353040350540583848053048835/bin-local/28365357253588565832552583773225/air.json:: [ERROR] El '/bin/2836535725358856583255258377322535814173588553871381528538535488582475527517870117081537583156781056785535031853587' está detelado en /clase/457547745745/contenedor/-15/air.json y air_image.dat!");
            for (int i = 0; i < 10 * 2; i++) {std::println("\a");}
            return;
        }
   } //++
    } // ma tran
    
   else if (toanvn.type_pheptinh == "5")
    {
        static std::stringstream input_shell(toanvn.inputs);
        static string command;
        auto input_tu_user = [&toanvn] () -> void
        {
        std::print("╔═</BangGaming8826/shell/> $» ");
        getline(cin >> ws, toanvn.inputs);
        input_shell.str("");
        input_shell.clear();
        input_shell << toanvn.inputs;
        input_shell >> command; 
        };
        std::println("/project/BangGaming8826/mode/shell/start.shell/start.cpp?");
        std::println("[i] The language is set to {}{}{} » {}{}{}", BangGaming8826::mau_do,"Vietnamese", BangGaming8826::res, BangGaming8826::vang,"English", BangGaming8826::res);
        std::println(".shell(input//100I);==\n");
        std::println("Welcome to bShell ===== ===== ===== =====");
        std::println("Type [help] or [?] to support; [info] to check vesion!");
        while(true)
        {
        input_tu_user();
        if (command == "help" || toanvn.inputs == "?") 
        {
            std::println("==Help Support - vers: 0.2===");
            std::println("exit : exit the shell");
            std::println("     |¯<num 1> <calculation: +,-,*,/,/:mod,^> <num 2> : calculator the number");
            std::println("     | <calculation: sigma, product> <start num> <end num>");
            std::println("     | <calculation: fact> <num>");
            std::println("     | <calculation: trig, hyp> <num> <r: rad, d: deg, g: gad>");
            std::println("     |                           |¯ 1: linear_equal> <num a> <num b> <num c: res>");
            std::println("     |                           |  2: quad_equal> <num a> <num b> <num c>");
            std::println("     |                           |  3: poly_equal> <num a> <num b> <num c> <num d>");
            std::println("     |                           |  4: rad_equal> <type: 1: sqrt(x) = y, 2: sqrt(ax+b)=c, 3: √ax+b = √cx+d>");
            std::println("calc | <calculation: equal><type |  5: abs_equal> <num a> <num b> <num c>");
            std::println("     |                           |  6: trig_equal> <sin/cos/tan;sinh/cosh/tanh> <number> <d, r, g> ");
            std::println("     |                           |  7: exp-log_equal> <equal_calc: ^, log> <base num> <return num>");
            std::println("     |                           |_ 8: system_equal> <num a1> <num a2> <num b1> <num b2> <num c1> <num c2>");
            std::println("     | <calculation: sqrt> <num> <tiers>");
            std::println("     | <calculation: abs> <num (REAL)> <is_vector_complex: bool> <num (IMAG)>");
            std::println("     | <calculation: ceil, floor> <num>");
            std::println("     | <calculation: round, nearyrint> <num> ");
            std::println("     | <calculation: int> <num b> <num a> <num c> <num d: of d²)");
	    std::println("     | <calculation: sort> <large->small: bool> <count> : <num a.... (infinite ∞)>");
            std::println("     |¯new <name: string> <path (end: '#')> <contents (with or no ws)>");
            std::println("     | <file type: detele, open> <path (end: '#')> <name: string>");
	    std::println("file | list <filter size: bool> <size of filter: num> <large->small: bool> <path>");
            std::println("     | rename <name_old: string> -> <name_new: string> <path>");
	    std::println("     |_search <name (end: '#')> <path>");
	    std::println("hardware <zoner: 0 or 1> <time: seconds: int>");
            //printf("%.531788560455865185865186855185651060015560051065878745784687848838454846461887561565885858851568851538853581517385173515858315835815858315358835581853815835881583515835881535886588486457856783056455815073761758173501721753231871573017658712070651781657815781758520250250025496734880506580084053530403505405838480530488350f", sym_pi);
            std::println("clr / clear : clear screen");
            std::println("Press any/Enter key to continue. . .");
            cin.ignore(1, '\n');
            cin.get();
            continue;
        }
        else  if (command == "exit")
        {
            std::println("Press any/Enter key to continue. . .");
            cin.ignore(1,'\n');
            cin.get();
            break;
        }
        else  if (toanvn.inputs == "clear" || toanvn.inputs == "clr") continue;
        else  if (command == "calc") 
        {
	    long double a,b,c,d,e,f;
            input_shell.clear();
            string pheptinh;
            input_shell >> pheptinh;
            if (pheptinh == "sigma")
            {
                input_shell >> toanvn.sothu1;
                input_shell >> toanvn.sothu2; 
                long long a = static_cast<long long>(toanvn.sothu1); //bắt đầu
                long long b = static_cast<long long>(toanvn.sothu2); //kết thúc
                long double c = 0;
                for (long double i = a; i <= b; i++) c += i;
                std::println("Result of ∑ {} -> {} = {}", a, b, c);
            }
            else if (pheptinh == "product")
            {
                input_shell >> toanvn.sothu1;
                input_shell >> toanvn.sothu2; 
                long long a = static_cast<long long>(toanvn.sothu1); //bắt đầu
                long long b = static_cast<long long>(toanvn.sothu2); //kết thúc
                long double c = 1;
                for (long double i = a; i <= b; i++) c *= i;
                std::println("Result of Π {} -> {} = {}", a, b, c);
            }
	    else if (pheptinh == "sort")
	    {  
		char quet;
		string hss;
		size_t bo_dem;
		bool den;
		input_shell >> std::boolalpha >> den;
		input_shell >> bo_dem;
		input_shell >> quet;
		vector<long double> nhom_spa_sapxep;
		if (bo_dem == 0) std::println("ERROR: InvalidVectorLocation_Size-T(return_exit(-1))");
		std::println("Result is: ");
		for (size_t i = 0; i <= bo_dem - 1; i++)
		{
			input_shell >> hss;
			long double scanna = chu_so_string(hss);
			nhom_spa_sapxep.push_back(scanna);
		}
		if (den == false) std::sort(nhom_spa_sapxep.begin(), nhom_spa_sapxep.end());
		else if (den == true) std::sort(nhom_spa_sapxep.begin(), nhom_spa_sapxep.end(), std::greater<long double>());
		for (size_t i = 0; i <= bo_dem - 1; i++) std::println("-> [{}] {}", i, nhom_spa_sapxep[i]);
		std::println("Start-Small Number (begin): {}",*nhom_spa_sapxep.begin());
		std::println("End-Large Number (end): {}",nhom_spa_sapxep.back());
	    }
            else if (pheptinh == "fact")
            {
                input_shell >> toanvn.sothu1;
                long long a = static_cast<long long>(toanvn.sothu1); //bắt đầu
                long double c = 1;
                for (long double i = 1; i <= a ; i++) c *= i;
                std::println("Result of {}! = {}",a, c);
            }
            else if (pheptinh == "trig")
            {
                string thich_nhin_ko, input_nhin_gi;
                input_shell >> input_nhin_gi;
		long double scanns = chu_so_string(input_nhin_gi);
                input_shell >> thich_nhin_ko;
                if (thich_nhin_ko == "r")
                {
                std::println("Result of sin({}r) = {}", scanns, sin(scanns));
                std::println("Result of cos({}r) = {}", scanns, cos(scanns));
                std::println("Result of tan({}r) = {}", scanns, tan(scanns));
                }
                else if (thich_nhin_ko == "d")
                {
                   std::println("Result of sin({}°) = {}", scanns, sin(scanns * sym_pi / 180));
                   std::println("Result of cos({}°) = {}", scanns, cos(scanns * sym_pi / 180));
                   std::println("Result of tan({}°) = {}", scanns, tan(scanns * sym_pi / 180));
                }
                else if (thich_nhin_ko == "g")
                {
                   std::println("Result of sin({}g) = {}", scanns, sin(scanns * sym_pi / 200));
                   std::println("Result of cos({}g) = {}", scanns, cos(scanns * sym_pi / 200));
                   std::println("Result of tan({}g) = {}", scanns, tan(scanns * sym_pi / 200));
                }
            }
            else if (pheptinh == "hyp")
            {
                string thich_nhin_ko, input_tu_usar;
                input_shell >> input_tu_usar;
		toanvn.sothu1 = chu_so_string(input_tu_usar);
                input_shell >> thich_nhin_ko;
                if (thich_nhin_ko == "r")
                {
                std::println("Result of sinh({}r) = {}", toanvn.sothu1, sinh(toanvn.sothu1));
                std::println("Result of cosh({}r) = {}", toanvn.sothu1, cosh(toanvn.sothu1));
                std::println("Result of tanh({}r) = {}", toanvn.sothu1, tanh(toanvn.sothu1));
                }
                else if (thich_nhin_ko == "d")
                {
                   std::println("Result of sinh({}°) = {}", toanvn.sothu1, sinh(toanvn.sothu1 * sym_pi / 180));
                   std::println("Result of cosh({}°) = {}", toanvn.sothu1, cosh(toanvn.sothu1 * sym_pi / 180));
                   std::println("Result of tanh({}°) = {}", toanvn.sothu1, tanh(toanvn.sothu1 * sym_pi / 180));
                }
                else if (thich_nhin_ko == "g")
                {
                   std::println("Result of sinh({}g) = {}", toanvn.sothu1, sinh(toanvn.sothu1 * sym_pi / 200));
                   std::println("Result of cosh({}g) = {}", toanvn.sothu1, cosh(toanvn.sothu1 * sym_pi / 200));
                   std::println("Result of tanh({}g) = {}", toanvn.sothu1, tanh(toanvn.sothu1 * sym_pi / 200));
                }
            }
            else if (pheptinh == "equal")
            {
                long double a /*x*/, b, c, d;
                string equal_typo, as,bs, cs, ds;
	                input_shell >> equal_typo;
                if (equal_typo == "linear_equal" || equal_typo == "1")
                {
                    input_shell >> as;
                    input_shell >> bs; 
                    input_shell >> cs;
		    a = chu_so_string(as), b = chu_so_string(bs), c = chu_so_string(cs);
                    std::println("Result of {}x + {} = {} is x={}",a, b, c, (c - b)/a);
                }
                else if (equal_typo == "quad_equal" || equal_typo == "2")
                {
                    input_shell >> as;
                    input_shell >> bs;
                    input_shell >> cs;
		    a = chu_so_string(as), b = chu_so_string(bs), c = chu_so_string(cs);
                    long double delta = (b*b) - (4.0*a*c);
                    if (delta > 0) std::println("Result of {}x² + {}x + {} is x1={} <|> x2={}", a,b,c,(-b+sqrt(delta))/(2*a),(-b-sqrt(delta))/(2*a));
                    else if (delta == 0) std::println("Result of {}x² + {}x + {} is x={}", a,b,c,(-b)/(2*a));
                    else 
                    {
                        auto find = complex<long double>(((-b) / (2.0*a)), 0) + (complex<long double>(((sqrt(abs(delta))) / (2*a)), 0) * complex<long double>(0, 1));
                        std::println("Result INFO: Delta_Inexperience(in dir:/projects/BangGaming8826/mode/shell/info/ResultINFO/res::format_equal_info_div?/)\nProgress with retured with 0 exit code\nor with complex: Result is x={} + {}i\n", find.real(), find.imag()); 
                    }
                }
                else if (equal_typo == "poly_equal" || equal_typo == "3")
                {
                    input_shell >> as;
                    input_shell >> bs;
                    input_shell >> cs;
                    input_shell >> ds;
		    a = chu_so_string(as), b = chu_so_string(bs), c = chu_so_string(cs), d = chu_so_string(ds);
                    long double so_trunggian = (3.0*a*c - b*b) / (3.0*a*a);
                    long double sotunhien_con_sot = (2.0*b*b*b - 9.0*a*b*c + 27.0*a*a*d) / (27.0*a*a*a);
                    long double delta = ((sotunhien_con_sot * sotunhien_con_sot) / 4.0) + ((so_trunggian * so_trunggian * so_trunggian) / 27.0);
                    
                    if (delta > 0) 
                    {
                        long double n1;
                        long double sieu1 = cbrt(-(sotunhien_con_sot / 2.0) + sqrt(delta));
                        long double sieu2 = cbrt(-(sotunhien_con_sot / 2.0) - sqrt(delta));
                        n1 = (sieu1 + sieu2) - (b / (3.0*a));
                        long double thuc = -((sieu1 + sieu2) / 2.0) - (b / (3.0*a));
                        long double ao = (sqrt(3.0)*(sieu1 - sieu2)) / 2.0;

                        std::println("Result is x={}", round(n1));
                        std::println("          x²={} + {}i", thuc, round(fabsl(ao)));
                        std::println("          x³={} — {}i", thuc, fabsl(ao));
                    }
                    else if (delta == 0)
                    {
                        if (so_trunggian == 0 &&sotunhien_con_sot == 0) std::println("Result of {}x³ + {}x² + {}x +m{} is x=x²=x³={}",a,b,c,d, round(((-b) / (3.0*a))));
                        else if (sotunhien_con_sot != 0 && so_trunggian != 0)
                        {
                            std::println("Result of {}x³ + {}x² + {}x + {} is x={}",a,b,c,d, round(((3.0*sotunhien_con_sot) / (so_trunggian)) - ((b) / (3.0*a))));
                            std::println("Result of {}x³ + {}x² + {}x + {} is x²=x³={}",a,b,c,d, round(-((3.0*sotunhien_con_sot) / (2.0*so_trunggian)) - ((b) / (3.0*a))) );
                        }
                    }
                    else if (delta < 0)
                    {
                        long double vava_agua = -powl(so_trunggian, 3.0L) / 27.0L;
                        long double agua = sqrtl(fmaxl(0.0L, vava_agua)); 
                        long double vava_agua2 = (agua != 0) ? (-sotunhien_con_sot / (2.0L * agua)) : 0.0L;
                        if (vava_agua2 > 1.0L) vava_agua2 = 1.0L;
                        else if (vava_agua2 < -1.0L) vava_agua2 = -1.0L;
                        long double agua2 = acosl(vava_agua2);
                        long double agua3 = 2.0L * sqrtl(fabsl(-(so_trunggian) / 3.0L));
                        long double omaichuoi = b / (3.0L * a);
                        std::println("Result of {}x³ + {}x² + {}x + {} is x={}",a,b,c,d, round(agua3 * cosl(agua2 / 3.0L) - omaichuoi));
                        std::println("                                    x²={}", round(agua3 * cosl((agua2 + 2.0L * sym_pi) / 3.0L) - omaichuoi));
                        cout << "                                    x³=" << round((agua3 * cosl((agua2 + 4.0L * sym_pi) / 3.0L) - omaichuoi)) << endl;
                    }
                    
                }
                else if (equal_typo == "rad_equal" || equal_typo == "4")
                {
                    int equal_num_typo = 0;
                    input_shell >> equal_num_typo;
                    if (equal_num_typo == 1)
                    {
                        std::println("Mode 1: √(x) = a");
                        std::print("Enter your number (a):");
                        cin >> as;
			a = chu_so_string(as);
                        if (a < 0) std::println("ERROR: The input is not a number (NaN)");
                        std::println("√(x) = {} is Result = {}", a, a * a);
                    }
                    if (equal_num_typo == 2)
                    {
                        std::println("Mode 2: √(ax + b) = c");
                        std::print("Enter your number (a >> b >> c):");
                        cin >> as >> bs >> cs;
			 a = chu_so_string(as), b = chu_so_string(bs), c = chu_so_string(cs);
                        if (c <= -1) std::print("ERROR: The input is not a number (NaN)");
                        else if (a == 0) std::print("ERROR: The input is not a number (NaN) and can't division by zero!"); 
                        std::println("√({}x + {}) = {} is Result = {}",a,b,c,(c*c - b)/a );
                    }
                    if (equal_num_typo == 3)
                    {
                        std::println("Mode 3: √(ax + b) = √(cx + d)");
                        std::print("Enter your number (a >> b >> c >> d): ");
                        cin >> as >> bs >> cs >> ds;
		        a = chu_so_string(as), b = chu_so_string(bs), c = chu_so_string(cs), d = chu_so_string(ds);
                        if (a == c) std::println("ERROR: The input is not a number (NaN) and can't division by zero!");
                        std::println("√({}xX + {}) = √({}x + {}) is Result = {}", a,b,c,d,(d-b)/(a-c));
                    }
                }
                else if (equal_typo == "abs_equal" || equal_typo == "5")
                {
                    input_shell >> as >> bs >> cs;
		     a = chu_so_string(as), b = chu_so_string(bs), c = chu_so_string(cs);
                    if (c >= 0) std::println("Result of |{}x + {}| = {} ; |{}x + {}| = {} ", a,b,(-c - b)/a ,a,b, (c - b)/a);
                    else if (c < 0) std::println("Result of  |{}x + {}| = {}. /projects/BangGaming8826/mode/shell/warning/scanning.cpp::Result_No_Solution", a,b,(-c - b)/a);
                }
                else if (equal_typo == "trig_equal" || equal_typo == "6")
                {
                    string goc, input_usar_nhin_gi;
                    input_shell >> input_usar_nhin_gi;
                    input_shell >> goc;
		    long double giatri = chu_so_string(input_usar_nhin_gi);
                    if (goc == "d")
                    {
                        std::println("sin(x) = {} is Result = {}°", giatri, asin(giatri) * 180 / sym_pi);
                        std::println("cos(x) = {} is Result = {}°", giatri, acos(giatri) * 180 / sym_pi);
                        std::println("tan(x) = {} is Result = {}°", giatri, atan(giatri) * 180 / sym_pi);
                        std::println("        ================");
                        std::println("sin(x) = {} is Result = {}°", giatri, asinh(giatri));
                        std::println("cos(x) = {} is Result = {}°", giatri, acosh(giatri));
                        std::println("tan(x) = {} is Result = {}°", giatri, atanh(giatri)); 
                    }
                    else if (goc == "r")
                    {
                        std::println("sin(x) = {} is Result = {}r", giatri, asin(giatri));
                        std::println("cos(x) = {} is Result = {}r", giatri, acos(giatri));
                        std::println("tan(x) = {} is Result = {}r", giatri, atan(giatri));
                        std::println("        ================");
                        std::println("sin(x) = {} is Result = {}r", giatri, asinh(giatri));
                        std::println("cos(x) = {} is Result = {}r", giatri, acosh(giatri));
                        std::println("tan(x) = {} is Result = {}r", giatri, atanh(giatri));
                    }
                    else if (goc == "g")
                    {
                        std::println("sin(x) = {} is Result = {}g", giatri, asin(giatri) * 200 / sym_pi);
                        std::println("cos(x) = {} is Result = {}g", giatri, acos(giatri) * 200 / sym_pi);
                        std::println("tan(x) = {} is Result = {}g", giatri, atan(giatri) * 200 / sym_pi);
                        std::println("        ================");
                        std::println("sin(x) = {} is Result = {}g", giatri, asinh(giatri));
                        std::println("cos(x) = {} is Result = {}g", giatri, acosh(giatri));
                        std::println("tan(x) = {} is Result = {}g", giatri, atanh(giatri));
                    }
                    
                }
                else if (equal_typo == "exp-log_equal" || equal_typo == "7")
                {
                    char pheptinh_logarit[90];
		    string nhin_gi1, nhin_gi2;
                    input_shell >> pheptinh_logarit;
                    input_shell >> nhin_gi1; //coso
                    input_shell >> nhin_gi2; // muso
		    long double coso = chu_so_string(nhin_gi1);
		    long double muso = chu_so_string(nhin_gi2);
                    if (pheptinh_logarit[0] == '^')
                    {
                        if (coso <= 0 || muso <= 0) std::println("ERROR: The input is not a number (NaN) and can't division by zero!");
                        else std::println("Result of {}^x = {} is = {}",coso, muso, (log(muso)) / (log(coso)));
                    }
                    else if (pheptinh_logarit[0] == 'l' && pheptinh_logarit[1] == 'o' && pheptinh_logarit[2] == 'g')
                    {
                        if (coso <= 0 || muso <= 0) std::println("ERROR: The input is not a number (NaN) and can't division by zero!");
                        else std::println("Result of log_{}(x) = {} is = {}", coso, muso, pow(coso, muso));
                    }
                }
                else if (equal_typo == "system_equal" || equal_typo == "8")
                {
		    string aw,av,bw, bv,cw,cv;
                    input_shell >> aw >> av >> bw >> bv >> cw >> cv;
		    long double a1 = chu_so_string(aw), a2 = chu_so_string(av), b1 = chu_so_string(bw), b2 = chu_so_string(bv), c1 = chu_so_string(cw), c2 = chu_so_string(cv);
                    long double phuong_chia = a1*b2 - a2*b1;
                    long double phuong1 = c1*b2 - c2*b1; //cho x ư?!
                    long double phuong2 = a1*c2 - a2*c1; // cho y ư?!
                    if (phuong_chia != 0) cout << "Result of a¹x + b¹y = c¹ and a²x + b²y = c² is x=" <<  phuong1/phuong_chia << " <|> y=" <<  phuong2/phuong_chia << endl;
                    else
                       {
                           std::println("There is no solution or there is an infinite number of solutions");
                           for (int i = 1; i <= 9; i++) std::println("ResultINFO: ExperimentInfo(in dir: /projects/BangGaming8826/mode/shell/info/ResultINFO/res::xp_equal_info_with_zero_div/)");
                       }
                }
            } //phuong trinh :)
            else if (pheptinh == "abs")
            {
                bool boolean_comp;
                bool comp_bool;
		string i1s, i2s;
                input_shell >> i1s;
		long double i1 = chu_so_string(i1s);
                input_shell >> std::boolalpha >> comp_bool;
                if (comp_bool == true)
                {
                    input_shell >> i2s;
		    long double i2 = chu_so_string(i2s);
                    auto kq = abs(complex<long double>(i1, i2));
                    std::println("Result of |{} + {}i| is {} ",i1, i2, kq);
                }
                else std::println("Result of |{}| is {}", i1, abs(i1));
            }
            else if (pheptinh == "ceil")
            {
                input_shell >> toanvn.inputs;
		toanvn.sothu1 = chu_so_string(toanvn.inputs);
                std::println("Result of ceil({}) OR |¯{}¯| is {}", toanvn.sothu1, toanvn.sothu1, ceil(toanvn.sothu1));
            }
            else if (pheptinh == "floor")
            {
                input_shell >> toanvn.inputs;
		toanvn.sothu2 = chu_so_string(toanvn.inputs);
                std::println("Result of floor({}) OR |_{}_| is {}", toanvn.sothu2, toanvn.sothu2, floor(toanvn.sothu2));
            }
            else if (pheptinh == "round")
            {
                input_shell >> toanvn.inputs;
		toanvn.sothu1 = chu_so_string(toanvn.inputs);
                std::println("Result of round({}) is {}", toanvn.sothu1, round(toanvn.sothu1));
            }
            else if (pheptinh == "nearyrint")
            {
                input_shell >> toanvn.inputs;
		toanvn.sothu1 = chu_so_string(toanvn.inputs);
                std::println("Result of nearbyint({}) = {} and rint({}) = {}", toanvn.sothu1, nearbyint(toanvn.sothu1), toanvn.sothu1, rint(toanvn.sothu1));
            }
            else if (pheptinh == "int")
            {
		string aq, bq, cq, dq;
                input_shell >> bq >> aq >> cq >> dq;
		long double a = chu_so_string(aq), b = chu_so_string(bq), c = chu_so_string(cq), d = chu_so_string(dq);
                std::println("Result of ∫({}, {}, x^{} dx) is {}",b,a,d, (pow(a, 3) / 3.0) - (pow(b, 3) / 3.0));
		std::println("Result of ∫({}, {}, {}dx) is {}", b,a,c, (c*pow(b, 2) / 2.0) - (c*pow(a, 2) / 2.0));
            }
            else if (pheptinh == "sqrt")
            {
		    string is1, is2;
                input_shell >> is1;
                input_shell >> is2;
		toanvn.sothu1 = chu_so_string(is1), toanvn.sothu2 = chu_so_string(is2);
                if (toanvn.sothu2 == 2) std::println("Result of ²√({}) = {}", toanvn.sothu1, sqrt(toanvn.sothu1));
                else if (toanvn.sothu2 == 3) std::println("Result of ³√({}) = {}", toanvn.sothu1, cbrt(toanvn.sothu1));
                else {std::println("Result of {}√({}) = {}", toanvn.sothu2, toanvn.sothu1, pow(toanvn.sothu1, 1.0 / toanvn.sothu2));}
            }
            else
            {
            toanvn.sothu1 = std::stold(pheptinh);
            input_shell >> toanvn.type_pheptinh;
            input_shell >> toanvn.sothu2;
            if (toanvn.type_pheptinh == "+")
            {
                toanvn.ket_qua = toanvn.sothu1 + toanvn.sothu2;
                std::println("Result of {} + {} = {:.16g} ",toanvn.sothu1, toanvn.sothu2, toanvn.ket_qua);
            }
            else if (toanvn.type_pheptinh == "-")
            {
                toanvn.ket_qua = toanvn.sothu1 - toanvn.sothu2;
                std::println("Result of {} — {} = {:.16g} ",toanvn.sothu1, toanvn.sothu2, toanvn.ket_qua);
            }
            else if (toanvn.type_pheptinh == "*")
            {
                toanvn.ket_qua = toanvn.sothu1 * toanvn.sothu2;
                std::println("Result of {} x {} = {:.16g} ",toanvn.sothu1, toanvn.sothu2, toanvn.ket_qua);
            }
            else if (toanvn.type_pheptinh == "/")
            {
                auto chia_loi_call = chia_loi(toanvn);
                toanvn.ket_qua = toanvn.sothu1 / toanvn.sothu2;
                std::println("Result of {} : {} or {} ÷ {} = {:.16g} ",toanvn.sothu1, toanvn.sothu2,toanvn.sothu1,toanvn.sothu2, toanvn.ket_qua);
            }
            else if (toanvn.type_pheptinh == "^")
            {
                toanvn.ket_qua = pow(toanvn.sothu1, toanvn.sothu2);
                std::println("Result of {}^{} = {:.16g} ",toanvn.sothu1, toanvn.sothu2, toanvn.ket_qua);
            }   
            else if (toanvn.type_pheptinh == "/:mod") 
            {
                auto chia_loi_call = chia_loi(toanvn);
                auto du = fmod(toanvn.sothu1, toanvn.sothu2);
                long long ketqua = toanvn.sothu1 / toanvn.sothu2;
                std::println("Result of {} : {} = {} mod {}", toanvn.sothu1, toanvn.sothu2, ketqua, du);
            }
        }
        //chung sống hòa thuận cùng continue;
            toanvn.sothu1 = 0; toanvn.sothu2 = 0;
            toanvn.type_pheptinh = "";  
        } // calc
        else if (command == "file")
        {
		input_shell.clear();
		auto xuongdong = [] (string &noi_dung_lambda, size_t postion = 0) -> string
		{
			while((postion = noi_dung_lambda.find("\\n", postion)) != string::npos)
			{
				noi_dung_lambda.replace(postion, 2, "\n");
				postion += 1;
			}
			return noi_dung_lambda;
		};
		auto duong_dan_file = [] (string dan_chi) -> void
		{
			input_shell >> dan_chi;
			if (std::filesystem::exists(dan_chi)) std::filesystem::path(dan_chi);
			else
			{
				std::println("Info: FolderNotFound()");
				std::println("Info: FolderNotFound(): The New folder is created!");
				std::filesystem::create_directories(dan_chi);
			}
		};
		auto loai_bo = [] (string &dau_zao) -> void
		{
			if (dau_zao.size() > 1 && dau_zao.back() == '/') dau_zao.pop_back();
		};
            string hang_dong;
	    string duong_dan = ".";
		    input_shell >> hang_dong;
            if (hang_dong == "new")
            {
                string ten, noidung;
                input_shell >> ten;
		getline(input_shell >> ws, duong_dan, '#');
                getline(input_shell >> ws, noidung);
		duong_dan_file(duong_dan);
                std::ofstream file_cua_user(ten);
                std::println("The new file with name '{}' is created!", ten);
                std::println("The file is it read: {} ", noidung);
                if (file_cua_user.is_open())
                {
                   file_cua_user << xuongdong(noidung) << std::endl;
                   file_cua_user.close();
                }
                else std::println("ERROR: FileError:  The file is can't create!"); 
            }
            else if (hang_dong == "open")
            {
                string ten, noidung;
                getline(input_shell >> ws, ten, '#');
		getline(input_shell >> ws, duong_dan, '#');
		duong_dan_file(duong_dan);
                std::ifstream input_file_cua_user(ten);
                if (input_file_cua_user.is_open())
                {
                std::println("Reading {} file, This is content in file: ", ten);
                input_file_cua_user >> ws;
                while(getline(input_file_cua_user, noidung)) cout << noidung << endl;
                input_file_cua_user.close();
                }
                else std::println("ERROR: FileError: '{}' is not a file or not found! <Treeback FUNC>", ten);
            }
            else if (hang_dong == "detele")
            {
                string ten;
                char confirm;
                getline(input_shell >> ws, ten, '#');
		getline(input_shell >> ws, duong_dan, '#');
		duong_dan_file(duong_dan);
                std::println("Do you want detele the file with name: '{}'?", ten);
                std::println("Enter 'y' to yes, 'n' to cancel: ");
                cin >> confirm;
                if (confirm == 'y') {if (std::filesystem::remove(ten)) {std::println("-> detele complete");}}
                else if (confirm == 'n') std::println("-> detele fail");
            }
            else if (hang_dong == "rename")
            {
                string cu, moi, amchi;
                getline(input_shell >> ws, cu, '#');
                input_shell >> amchi;
                getline(input_shell >> ws, moi, '#');
		getline(input_shell >> ws, duong_dan, '#');
		duong_dan_file(duong_dan);
                loi_file(cu, moi);
            }
	    else if (hang_dong == "list")
	    {
		    bool co_do_ko, to_nho;
		    int so = 0;
		    uintmax_t qua_nhieu_dung_luong = 0, do_dung_luong = 0;
		    input_shell >> boolalpha >> co_do_ko;
		    input_shell >> do_dung_luong;
		    input_shell >> boolalpha >> to_nho;
		    getline(input_shell >> ws, duong_dan, '#');
		    std::println("——File/Folder name—————————Path (DIR)————————————Size of file——");
		    if (std::filesystem::exists(duong_dan))
		    { 
		    	for (const auto &i : std::filesystem::recursive_directory_iterator(duong_dan))
		    	{  
				if (std::filesystem::is_regular_file(i.status())) 
				{
					so += 1;
					if (co_do_ko == false)
					{
						qua_nhieu_dung_luong += std::filesystem::file_size(i);
						std:println("{} • {}  	 {:^15}	    {:.6f} kB", so, i.path().filename().string(), i.path().string(), i.file_size() / 1024.0L);
					}
					else if (co_do_ko == true)
					{
						if (to_nho == true)
						{
							if ((i.file_size() / 1024.0L) > do_dung_luong)
							{
								qua_nhieu_dung_luong += std::filesystem::file_size(i);
								std::println("{} • {}	{:^15}	   {:.6f} kB", so, i.path().filename().string(), i.path().string(), i.file_size() / 1024.0L);
							}
						}
						else if (to_nho == false)
						{
							if ((i.file_size() / 1024.0L) < do_dung_luong)
							{
								qua_nhieu_dung_luong += std::filesystem::file_size(i);
								std::println("{} • {}	{:^15}	   {:.6f} kB", so, i.path().filename().string(), i.path().string(), i.file_size() / 1024.0L);
							}
						}
					}
				} 
	    		}
		    }	
		else std::println("ERROR: FileNotFoundOfInvaild(with return of func: -1)");
	    }
	    else if (hang_dong == "search")
	    {
		    bool nhin_qq = false;
		    int so = 0;
		    string ten, diachi, ht;
		    getline(input_shell >> ws, ten, '#');
		    getline(input_shell >> ws, diachi, '#');
		    std::println("——File/Folder—————————Path (DIR)———————Size of file——");
		    if (std::filesystem::exists(diachi))
		    {
			    try
			    {
		    		for (const auto &i : std::filesystem::recursive_directory_iterator(diachi))
				{
					ht = i.path().string();
					size_t tim_kiem_so = ht.find(ten);
					if (tim_kiem_so != string::npos)
					{
						nhin_qq = true;
						so += 1;
						std::println("{} • {}	  {}   {:.6f} kB",so, i.path().filename().string(), i.path().string(), i.file_size() / 1024.0L);
					}
				}
			    }
			    catch (...)
			    {
				    std::println("ERROR: FileError(with return 0) <-> []—[]—[]—[]—[]");
				    std::println("[i] No Matching to You Search :3");
			    }
		    }
	    }
	}
	else if (command == "hardware")
	{
		int zone_cpu, time;
		char ko_dc_nhin;
		input_shell >> zone_cpu >> time;
		if (zone_cpu < 0 && zone_cpu > 1)
		{
			std::println("The zone can't {}!", zone_cpu);
			std::println("ERROR: ZoneInvaildOfDevice(): Info: set to 0 (default) complete!");
			zone_cpu = 0;
		}
		else
		{
			for (int i = 1; i < time; i++)
			{
				std::print("\033[H\033[J");
				hardware_operator(zone_cpu);
				std::this_thread::sleep_for(std::chrono::seconds(1));
			}
		}
	}
        else if (command == "info")  BangGaming8826::dev_info(true);
        else std::println("'{}' is not a command in system. Do you mean 'exit'? or it's a compressed file.", command);
        continue;
       }//for (int i =0; i < i+1; i +0), hay de y den cac toan tu :)
    } // shell
}
// :D 
void toanviet(Toanhoc toanvn)
{
     
    //¡cin cho các phép tính. Ko nên cho cin.ignore() để xóa enter!
    //¡No pongas cin.ignore() aquí, ni apliques la mano dominante y la regla de la mano traviesa de las madres asiáticas en
    //endl lambda 
    //run và... VN
    #ifdef _WIN32
       GiaoDien::windows_window(175, 100, 200, 100, 200);
    #elif __linux__ 
       GiaoDien::delay_text(500 * 100, string("Developer Calculator - ") + string(BangGaming8826::xanh_la) + string("BangGaming8826") + string(BangGaming8826::res));
       GiaoDien::delay_text(1, "===========================================");
    #endif
    lang_vietnam();
    cin >> toanvn.type_pheptinh;
    
   //claculator?! hí hí:
   if (toanvn.type_pheptinh == "mode")
   {
       #ifdef _WIN32
          system("cls");
          mode(toanvn);
       #else
          system("clear");
          mode(toanvn);
       #endif   
   }
   
   if (toanvn.type_pheptinh == "sqrt")
   {
       string a;
       std::print("Chọn kiểu căn ([sq2] tính căn bậc 2, [n] Tính căn bậc n, [cq3] Tính căn bậc 3): ");
       cin >> a;
       
       //BẬC 2:
       if (a == "sq2")
       {
           std::print("Nhập đầu vào: ");
           cin >> toanvn.sothu2;
           toanvn.ket_qua = sqrt(toanvn.sothu2);
           std::println("Kết quả của căn bậc 2 của {} là: {}", toanvn.sothu2 , toanvn.ket_qua);
          string theclear = clear_screen();
          (void)theclear;
       }//end bậc 2!
       
       if (a == "n")
       {
           std::print("Nhập bậc của căn: ");
           cin >> toanvn.sothu1;
           std::print("Nhập đầu vào: ");
           cin >> toanvn.sothu2;
           toanvn.ket_qua = pow(toanvn.sothu2, 1.0 / toanvn.sothu1);
           std::println("Kết của của căn bậc {} của {} là: {}", toanvn.sothu1, toanvn.sothu2, toanvn.ket_qua);
       string theclear = clear_screen();
       (void)theclear;
   } // end of sqrt(n)
   
   if (a == "cq3")
   {
       std::print("Nhập đầu vào: ");
       cin >> toanvn.sothu2;
       toanvn.ket_qua = cbrt(toanvn.sothu2);
       std::println("Kết của của căn bậc 3 của {} là: {}", toanvn.sothu2, toanvn.ket_qua);
        string theclear = clear_screen();
        (void)theclear;
   } // sqrt 3
   
   } // sqrt
   
   if (toanvn.type_pheptinh == "||")
   {
       string hamso;
       std::print("Nhập kiểu hàm số ([gttd] Giá trị tuyệt đối, [tr] Trần, [sn] Sàn): ");
       cin >> hamso;
       
       //GIÁ TRỊ TUYỆT ĐỐI: 
       if (hamso == "gttd")
       {
           std::print("Nhập đầu vào: ");
           cin >> toanvn.sothu2;
           toanvn.ket_qua = abs(toanvn.sothu2);
           std::println("Kết quả của |{}| là: {}", toanvn.sothu2, toanvn.ket_qua);
            string theclear = clear_screen();
            (void)theclear;
       } //tuyệt đối.end;
       
      //TRẦN: 
    if (hamso == "tr")
    {
        std::print("Nhập đầu vào: ");
        cin >> toanvn.sothu2;
        toanvn.ket_qua = ceil(toanvn.sothu2);
        std::println("Kết của của |¯{}¯| là: {}", toanvn.sothu2, toanvn.ket_qua);
        string theclear = clear_screen();
        (void)theclear;
    } // TRẦN.END;
    
    if (hamso == "sn")
    {
       std::print("Nhập đầu vào: ");
       cin >> toanvn.sothu2;
       toanvn.ket_qua = floor(toanvn.sothu2);
       std::println("Kết quả của |_{}_| là: {}", toanvn.sothu2, toanvn.ket_qua);
       string theclear = clear_screen();
       (void)theclear;
    } // SÀN.END;
   } // hàm số 
   
   if (toanvn.type_pheptinh == "log")
   {
       std::print("Nhập đầu vào: ");
       cin >> toanvn.sothu2;
       if (toanvn.sothu2 <=0)

{
    std::println("Log cơ số 10 không thể chia cho 0!");
    string theclear=clear_screen();
    (void)theclear;
}
     //đk 0 1
   

else
{
       toanvn.ket_qua = log10(toanvn.sothu2);
       std::println("Kết quả của log({}) là: {}", toanvn.sothu2, toanvn.ket_qua);
       string theclear = clear_screen();
       (void)theclear;
   } // eo sa băng tuyết :)
    }// log!
   
   if (toanvn.type_pheptinh == "log_x")
   {
       std::print("Nhập cơ số: ");
       cin >> toanvn.sothu1;
       std::print("Nhập kết của của cơ số & mũ số: ");
       cin >> toanvn.sothu2;
       toanvn.ket_qua = log(toanvn.sothu2) / log(toanvn.sothu1);
       std::println("Kết quả của log_{}({}) là: {}", toanvn.sothu1, toanvn.sothu2, toanvn.ket_qua);
       string theclear = clear_screen();
       (void)theclear;
   } // log cơ số x
   
   if (toanvn.type_pheptinh == "ln")
   {
      std::print("Nhập đầu vào: ");
      cin >> toanvn.sothu2;
      toanvn.ket_qua = log(toanvn.sothu2);
      std::println("Kết của của ln({}) là: {}", toanvn.sothu2, toanvn.ket_qua);
      string theclear = clear_screen();
      (void)theclear;
   } // ln(x)

    if (toanvn.type_pheptinh == "+")
    {
        cout << "Enter your number 1: ";
        cin >> toanvn.sothu1;
        cout << "Nhập số thứ 2: ";
        cin >> toanvn.sothu2;
        toanvn.ket_qua = toanvn.sothu1 + toanvn.sothu2;
        cout << "Kết quả của phép tính: " << toanvn.sothu1 << " + " << toanvn.sothu2 <<" là: " << toanvn.ket_qua << endl;
        string theclear = clear_screen();
        (void)theclear;
    } // cộng!?

    if (toanvn.type_pheptinh == "-")
    {
        cout << "Enter your number 1: ";
        cin >> toanvn.sothu1;
        cout << "Nhập số thứ 2: ";
        cin >> toanvn.sothu2;
        toanvn.ket_qua = toanvn.sothu1 - toanvn.sothu2;
        cout << "Kết quả của phép tính: " << toanvn.sothu1 << " - " << toanvn.sothu2 <<" là: " << toanvn.ket_qua << endl;
        string theclear = clear_screen();
        (void)theclear;
    } //trừ

    if (toanvn.type_pheptinh == "x")
    {
        cout << "Enter your number 1: ";
        cin >> toanvn.sothu1;
        cout << "Nhập số thứ 2: ";
        cin >> toanvn.sothu2;
        toanvn.ket_qua = toanvn.sothu1 * toanvn.sothu2;
        cout << "Kết quả của phép tính: " << toanvn.sothu1 << " x " << toanvn.sothu2 <<" là: " << toanvn.ket_qua << endl;
        string theclear = clear_screen();
        (void)theclear;
    } //nhân

    if (toanvn.type_pheptinh == "÷")
    {   
       long double a;
       long double b;
        cout << "Enter your number 1: ";
        cin >> a;
        cout << "Nhập số thứ 2: ";
        cin >> b;
        if (b == 0) 
        {
          cout << "Không thể chia cho 0!" << endl;
          string theclear = clear_screen();
        }// Tim loi thay try-catch
        
        toanvn.ket_qua = toanvn.sothu1 / toanvn.sothu2;
        cout << "Kết quả của phép tính: " << toanvn.sothu1 << " ÷ " << toanvn.sothu2 <<" là: " << toanvn.ket_qua << endl;
        string theclear = clear_screen();
        (void)theclear;
    } //chia

    if (toanvn.type_pheptinh == "^")
    {
        cout << "Nhập cơ số: ";
        cin >> toanvn.sothu1;
        cout << "Nhập mũ số: ";
        cin >> toanvn.sothu2;
        toanvn.ket_qua = pow(toanvn.sothu1, toanvn.sothu2);
        cout << "Kết quả của: " << toanvn.sothu1 <<"^"<< toanvn.sothu2 << " là: " << toanvn.ket_qua <<endl;
        string theclear = clear_screen();
        (void)theclear;
    } //mũ

    if (toanvn.type_pheptinh == "10^y")
    {
        cout << "Nhập mũ số: ";
        cin >> toanvn.sothu2;
        toanvn.ket_qua = pow(10, toanvn.sothu2);
        cout << "Kết quả của: 10^" << toanvn.sothu2 << " là: " << toanvn.ket_qua << endl;
        string theclear = clear_screen ();
        (void)theclear;
    } //mũ 10

    if (toanvn.type_pheptinh == "x!")
    {
        cout << "[!] Lưu ý: Chỉ tính được đến 20!" << endl;
        cout << "Nhập số: ";
        cin >> toanvn.sothu1;
        toanvn.ket_qua = 1;
        for (int i = 1; i <= toanvn.sothu1; i++)
        {
            toanvn.ket_qua *= i;
        }//for
        cout << "Kết quả của " << toanvn.sothu1 << "! là: " << toanvn.ket_qua << endl;
        string theclear = clear_screen(); 
        (void)theclear;
    } // giai thừa

    if (toanvn.type_pheptinh == "sin")
    {
        string typesin;
        cout << "Chọn kiểu tính sin ([d] độ, [r] radian): ";
        cin >> typesin;

        if (typesin == "r")
        {
            cout << "Nhập đầu vào: ";
            cin >> toanvn.sothu1;
            toanvn.ket_qua = sin(toanvn.sothu1);
            cout << "Kết quả của sin("<< toanvn.sothu1 << ") là: " << toanvn.ket_qua << endl;
            string theclear = clear_screen();
            (void)theclear;
        }

        if (typesin == "d")
        {
            cout << "Nhập đầu vào: ";
            cin >> toanvn.sothu2;
            toanvn.sothu1 = toanvn.sothu2 * (sym_pi / 180);
            toanvn.ket_qua = sin(toanvn.sothu1);
            cout << "Kết quả của sin(" << toanvn.sothu2 << "°) là: " << toanvn.ket_qua << endl;
            string theclear = clear_screen();
            (void)theclear;
        }
    } //sin sinh

    if (toanvn.type_pheptinh == "cos")
    {
        string typecos;
        cout << "Chọn kiểu tính cos ([d] độ, [r] radian): ";
        cin >> typecos;

        if (typecos == "r")
        {
            cout << "Nhập đầu vào: ";
            cin >> toanvn.sothu1;
            toanvn.ket_qua = cos(toanvn.sothu1);
            cout << "Kết quả của cos(" << toanvn.sothu1 << ") là: " << toanvn.ket_qua << endl;
            string theclear = clear_screen();
            (void)theclear;
        }

        if (typecos == "d")
        {
            cout << "Nhập đầu vào: ";
            cin >> toanvn.sothu2;
            toanvn.sothu1 = toanvn.sothu2 * (sym_pi / 180);
            toanvn.ket_qua = cos(toanvn.sothu1);
            cout << "Kết quả của cos(" << toanvn.sothu2 << " độ) là: " << fixed << toanvn.ket_qua << endl;
            string theclear = clear_screen();           
            (void)theclear;
        }

    }

    if (toanvn.type_pheptinh == "tan")
    {
        string typetan;
        cout << "Nhập kiểu tính tan ([d] độ, [r] radian): ";
        cin >> typetan;

        if (typetan == "d")
        {
            cout << "Nhập đầu vào (lớn hơn 90° thì tan tiến tới vô cùng): ";
            cin >> toanvn.sothu2;
            toanvn.sothu1 = toanvn.sothu2 * (sym_pi / 180);
            toanvn.ket_qua = tan(toanvn.sothu1);
            cout << "Kết quả của tan(" << toanvn.sothu2 <<" độ) là: " <<toanvn.ket_qua << endl;
            string theclear = clear_screen();
            (void)theclear;
        }


        if (typetan == "r")
        {
            cout << "Nhập đầu vào: ";
            cin >> toanvn.sothu1;
            toanvn.ket_qua = tan(toanvn.sothu1);
            cout << "Kết quả của tan(" << toanvn.sothu1 << ") là: " << fixed <<toanvn.ket_qua << endl;
            string theclear = clear_screen();
            (void)theclear;
        }
    } //el tan
    
    if (toanvn.type_pheptinh == "hyp")
    {
        string stdf;
       std::print("Nhập kiểu cho hyp (sinh, cosh, tanh): ");
       cin >> stdf;
       
       if (stdf == "sinh")
       {
           std::print("Nhập đầu vào: ");
           cin >> toanvn.sothu2;
           toanvn.ket_qua = sinh(toanvn.sothu2);
           std::println("Kết quả của sinh({}) là: {} ", toanvn.sothu2, toanvn.ket_qua);
           string theclear = clear_screen();
           (void)theclear;
       
    }
    
    if (stdf == "cosh")
    {
        std::print("Nhập đầu vào: ");
        cin >> toanvn.sothu2;
        toanvn.ket_qua = cosh(toanvn.sothu2);
        std::println("Kết quả của cosh({}) là: {}", toanvn.sothu2, toanvn.ket_qua);
        string theclear = clear_screen();
        (void)theclear;
    }
    
    if (stdf == "tanh")
    {
        std::print("Nhập đầu vào: ");
        cin >> toanvn.sothu2;
        toanvn.ket_qua = tanh(toanvn.sothu2);
        std::println("Kết quả của tanh({}) là: {}", toanvn.sothu2, toanvn.ket_qua);
        string theclear = clear_screen();
        (void)theclear;
    }
}

    if (toanvn.type_pheptinh == "import-answer")
    {
        string answ_vnm;
        cout << "Enter tên biến bạn muốn đặt (VD: x,a,y,z)?: ";
        cin >> answ_vnm;
        cout << "Nhập giá trị muốn lưu?: ";
        cin >> toanvn.ket_qua;

        //Save to Value(?)
        luu_gia_tri[answ_vnm] = toanvn.ket_qua;
        cout << "Đã lưu kết quả vào " << answ_vnm<< endl;
        string theclear = clear_screen();
        (void)theclear;
    }//imp ans

    if (toanvn.type_pheptinh == "export-answer")
    {
        string answ_e;
        cout << "Nhập giá trị cần xuất: ";
        cin >> answ_e;

        if (luu_gia_tri.count(answ_e))
        {
            cout << "Giá trị của " << answ_e << " là: " << luu_gia_tri[answ_e] << endl;
            string theclear = clear_screen();
        } // xuất : Ok

        else
        {
            cout << "Biến chưa được lưu. Thử lại..." << endl;
            string theclear = clear_screen();
            (void)theclear;
        }

    }//exp ans

    if (toanvn.type_pheptinh == "delete-answer")
    {
        string answ_del;
        cout << "Nhập tên biến cần xóa: ";
        cin >> answ_del;

        if (luu_gia_tri.count(answ_del))
        {
            luu_gia_tri.erase(answ_del);
            cout << "Đã xóa thành công..." << endl;
            string theclear = clear_screen();           
        }//er=true!

    } // del ans

    if (toanvn.type_pheptinh == "list-answer")
    {
        system("clear");
        cout << "Danh sách đã lưu [biến] ========" << endl;

        if (luu_gia_tri.empty())
        {
            cout << " (?) Không có gì tại đây..." << endl;
            string theclear = clear_screen();
            (void)theclear;
        }
        else
        {
            for (auto const& x : luu_gia_tri)
            {
                cout << "Giá trị của " << x.first << " = " << x.second << endl;
            }
            string theclear = clear_screen();
            (void)theclear;
        }


    }
    
    else
    {
       cout << "Cú pháp không nằm trong thư viện máy tính SLL!";
        cout << "Vui lòng nhấn Enter để tiếp tục . . . . .";
        cin.ignore(1,'\n');
        cin.get();
        system("clear");
        return toanviet(toanvn);
    }
}
int main(int argc, char** argv)
{
    while(true) mode(toanvn);
}
