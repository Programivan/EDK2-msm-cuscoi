// ACPI Tables
FILE FREEFORM = 7E374E25-8E01-4FEE-87F2-390C23C606CD {   
  SECTION RAW = Silicon/Qualcomm/sm7435/AcpiTables/dbg2.aml
  SECTION RAW = Platform/Motorola/sm7435/AcpiTables/cuscoi/DSDT.aml
  SECTION RAW = Silicon/Qualcomm/sm7435/AcpiTables/Madt.aml
  SECTION RAW = Silicon/Qualcomm/sm7435/AcpiTables/Facp.aml
  SECTION RAW = Silicon/Qualcomm/sm7435/AcpiTables/Gtdt.aml
  SECTION RAW = Silicon/Qualcomm/sm7435/AcpiTables/IORT.aml
  SECTION RAW = Silicon/Qualcomm/sm7435/AcpiTables/Pptt.aml
  SECTION UI = "AcpiTables"
}

// Mainline device tree blob
FILE FREEFORM = 25462CDA-221F-47DF-AC1D-259CFAA4E326 {
  SECTION RAW = Platform/Motorola/sm7435/FdtBlob_compat/cuscoi.dtb
}
