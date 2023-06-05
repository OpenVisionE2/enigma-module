#include <linux/version.h>
#include <linux/string.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/namei.h>
#include <linux/seq_file.h>
#include <linux/proc_fs.h>
#include <linux/delay.h>
#include <linux/uaccess.h>
#include <linux/platform_device.h>
#include <linux/kernel.h>

#define MAX_CHAR_LENGTH 256
#define cProcDir	1
#define cProcEntry	2

struct ProcWriteInfo
{
	int proc_i;
	int count;
	int ipage;
	char *bpage;
	const char __user *ubuf;
};

typedef int (*proc_read_t) (struct seq_file *m, void* data);
typedef int (*proc_write_t_e2) (struct ProcWriteInfo *proc_info, char *kbuf);

struct ProcStructure_s
{
	int type;
	char* name;
	struct proc_dir_entry* entry;
	proc_read_t read_proc;
	proc_write_t_e2 write_proc;
	struct ProcWriteInfo* proc_info;
	void* identifier; /* needed for cpp stuff */
};

struct file* file_open(const char* path, int flags, int rights);
void file_close(struct file* file);
int file_read(struct file* file, unsigned char* data, unsigned int size);
int file_write(struct file* file, unsigned char* data, unsigned int size);
int remove_file(char *path);
int save_data_to_file(char *path, int flags, char *data, int size);
char * dirname(char * name);
char * basename(char * name);

int get_enigma_allinfo(struct seq_file *m, void* data);
int get_enigma_architecture(struct seq_file *m, void* data);
int get_enigma_avjack(struct seq_file *m, void* data);
int get_enigma_blindscanbinary(struct seq_file *m, void* data);
int get_enigma_brand(struct seq_file *m, void* data);
int get_enigma_ci(struct seq_file *m, void* data);
int get_enigma_compiledate(struct seq_file *m, void* data);
int get_enigma_dboxlcd(struct seq_file *m, void* data);
int get_enigma_developername(struct seq_file *m, void* data);
int get_enigma_displaybrand(struct seq_file *m, void* data);
int get_enigma_displaydistro(struct seq_file *m, void* data);
int get_enigma_displaymodel(struct seq_file *m, void* data);
int get_enigma_displaytype(struct seq_file *m, void* data);
int get_enigma_distro(struct seq_file *m, void* data);
int get_enigma_driverdate(struct seq_file *m, void* data);
int get_enigma_emmc(struct seq_file *m, void* data);
int get_enigma_fan(struct seq_file *m, void* data);
int get_enigma_feedsurl(struct seq_file *m, void* data);
int get_enigma_fhdskin(struct seq_file *m, void* data);
int get_enigma_forcemode(struct seq_file *m, void* data);
int get_enigma_fpu(struct seq_file *m, void* data);
int get_enigma_friendlyfamily(struct seq_file *m, void* data);
int get_enigma_hdmifhdin(struct seq_file *m, void* data);
int get_enigma_hdmihdin(struct seq_file *m, void* data);
int get_enigma_hdmi(struct seq_file *m, void* data);
int get_enigma_imagebuild(struct seq_file *m, void* data);
int get_enigma_imagedevbuild(struct seq_file *m, void* data);
int get_enigma_imagedir(struct seq_file *m, void* data);
int get_enigma_imagefs(struct seq_file *m, void* data);
int get_enigma_imagetype(struct seq_file *m, void* data);
int get_enigma_imageversion(struct seq_file *m, void* data);
int get_enigma_imglanguage(struct seq_file *m, void* data);
int get_enigma_imgrevision(struct seq_file *m, void* data);
int get_enigma_imgversion(struct seq_file *m, void* data);
int get_enigma_kernelfile(struct seq_file *m, void* data);
int get_enigma_kernel(struct seq_file *m, void* data);
int get_enigma_mediaservice(struct seq_file *m, void* data);
int get_enigma_middleflash(struct seq_file *m, void* data);
int get_enigma_mkubifs(struct seq_file *m, void* data);
int get_enigma_mmc(struct seq_file *m, void* data);
int get_enigma_model(struct seq_file *m, void* data);
int get_enigma_mtdbootfs(struct seq_file *m, void* data);
int get_enigma_mtdkernel(struct seq_file *m, void* data);
int get_enigma_mtdrootfs(struct seq_file *m, void* data);
int get_enigma_multilib(struct seq_file *m, void* data);
int get_enigma_multitranscoding(struct seq_file *m, void* data);
int get_enigma_oe(struct seq_file *m, void* data);
int get_enigma_platform(struct seq_file *m, void* data);
int get_enigma_rca(struct seq_file *m, void* data);
int get_enigma_rcidnum(struct seq_file *m, void* data);
int get_enigma_rcname(struct seq_file *m, void* data);
int get_enigma_rctype(struct seq_file *m, void* data);
int get_enigma_rootfile(struct seq_file *m, void* data);
int get_enigma_scart(struct seq_file *m, void* data);
int get_enigma_smallflash(struct seq_file *m, void* data);
int get_enigma_socfamily(struct seq_file *m, void* data);
int get_enigma_svideo(struct seq_file *m, void* data);
int get_enigma_transcoding(struct seq_file *m, void* data);
int get_enigma_ubinize(struct seq_file *m, void* data);
int get_enigma_uhd4k(struct seq_file *m, void* data);
int get_enigma_vfdsymbol(struct seq_file *m, void* data);
int get_enigma_wol(struct seq_file *m, void* data);
int get_enigma_yuv(struct seq_file *m, void* data);
